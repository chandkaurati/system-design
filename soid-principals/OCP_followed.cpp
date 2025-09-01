#include <iostream>
#include <vector>
using namespace std;

// OCP: Open/Closed Principle
// A class should be open for extension but closed for modification.
// modification means changing existing code.
// extension means adding new code/feature.

class Product
{
public:
    string name;
    double price;

    Product(string name, double price)
    {
        this->name = name;
        this->price = price;
    }
};

// 1. ShoppingCart: Only responsible for Cart related business logic.

class ShoppingCart
{
private:
    vector<Product *> products; // Store heap-allocated products

public:
    void addProduct(Product *p)
    {
        products.push_back(p);
    }

    const vector<Product *> &getProducts()
    {
        return products;
    }

    // Calculates total price in cart.
    double calculateTotal()
    {
        double total = 0;
        for (auto p : products)
        {
            total += p->price;
        }
        return total;
    }
};

class ShoppingCartPrinter
{
private:
    ShoppingCart *cart;

public:
    ShoppingCartPrinter(ShoppingCart *cart)
    {
        this->cart = cart;
    }

    void printInvoice()
    {
        cout << "Shopping Cart Invoice:\n";
        for (auto p : cart->getProducts())
        {
            cout << p->name << " - Rs " << p->price << endl;
        }
        cout << "Total: Rs " << cart->calculateTotal() << endl;
    }
};

// Base class for persistence mechanisms
class Persistance
{
private:
    ShoppingCart *cart;

public:
    virtual void save() = 0; // Abstract method for saving cart
};

// OCP is simulated here: We can add new persistence mechanisms (e.g., SQL, MongoDB, File)
// without modifying the existing code. We achieve this by extending the `Persistance` class.

class SQLPersistance : public Persistance
{
public:
    void save() override
    {
        cout << "Saving shopping cart to SQL DB..." << endl;
    }
};

class MongoPersistance : public Persistance
{
public:
    void save() override
    {
        cout << "Saving shopping cart to MongoDB..." << endl;
    }
};

class FilePersistance : public Persistance
{
public:
    void save() override
    {
        cout << "Saving shopping cart to a file..." << endl;
    }
};

int main()

{

    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));

    ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart); 
    printer->printInvoice();

    // OCP in action: We can use different persistence mechanisms without modifying existing code.
    Persistance* db = new SQLPersistance();
    Persistance* mongo = new MongoPersistance();
    // Persistance* file

    db->save();
    mongo->save();
    // file->save();

    return 0;
}