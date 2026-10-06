#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product {
public:
    int id;
    string name;
    int quantity;
    double price;

    Product(int i, string n, int q, double p)
        : id(i), name(n), quantity(q), price(p) {}
};

class Inventory {
    vector<Product> products;
public:
    void addProduct(Product p) { products.push_back(p); }

    void displayProducts() {
        cout << "\n--- Inventory ---\n";
        for (const auto& p : products)
            cout << p.id << " | " << p.name << " | Qty: "
                 << p.quantity << " | Price: Rs." << p.price << '\n';
    }

    void searchProduct(string key) {
        for (const auto& p : products) {
            if (p.name.find(key) != string::npos) {
                cout << "Found: " << p.name << " | Qty: "
                     << p.quantity << " | Rs." << p.price << '\n';
                return;
            }
        }
        cout << "Product not found.\n";
    }
};

int main() {
    Inventory inventory;
    inventory.addProduct(Product(101, "Wireless Mouse", 24, 799));
    inventory.addProduct(Product(102, "Keyboard", 15, 1299));
    inventory.addProduct(Product(103, "USB Hub", 8, 599));

    int choice;
    do {
        cout << "\n1. Display Products\n2. Search Product\n3. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) inventory.displayProducts();
        else if (choice == 2) {
            string key;
            cout << "Enter product name: ";
            cin >> key;
            inventory.searchProduct(key);
        }
    } while (choice != 3);

    return 0;
}
