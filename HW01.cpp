#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base class for Inventory system
class InventorySystem {
protected:
    int productID;
    string name;
    float price;
    int amount_in_inventory;

public:
    InventorySystem(int productID, string name, float price, int amount_in_inventory)
        : productID(productID), name(name), price(price), amount_in_inventory(amount_in_inventory) {}

    virtual ~InventorySystem() {
        // Destructor implementation (if needed)
    }

    virtual void display_info() {
        cout << "Product ID: " << productID << ", Name: " << name << ", Price: $" << price
             << ", Available: " << amount_in_inventory << endl;
    }

    void buy_item(int quantity) {
        if (amount_in_inventory >= quantity) {
            amount_in_inventory -= quantity;
            cout << "Purchased " << quantity << " " << name << "(s)." << endl;
        } else {
            cout << "Not enough stock for " << name << ". Only " << amount_in_inventory << " available." << endl;
        }
    }

    void restock_item(int quantity) {
        amount_in_inventory += quantity;
        cout << "Restocked " << quantity << " " << name << "(s). Now available: " << amount_in_inventory << "." << endl;
    }

    int getProductID() const {
        return productID;
    }
};

// Derived class for Indoor Sports category
class IndoorSports : public InventorySystem {
public:
    IndoorSports(int productID, string name, float price, int amount_in_inventory)
        : InventorySystem(productID, name, price, amount_in_inventory) {}
};

// Derived class for Outdoor Sports category
class OutdoorSports : public InventorySystem {
public:
    OutdoorSports(int productID, string name, float price, int amount_in_inventory)
        : InventorySystem(productID, name, price, amount_in_inventory) {}
};

// Volleyball subclass
class Volleyball : public IndoorSports {
private:
    string type_of_item;
public:
    Volleyball(int productID, string name, float price, int amount_in_inventory, string type_of_item)
        : IndoorSports(productID, name, price, amount_in_inventory), type_of_item(type_of_item) {}

    void display_info() override {
        InventorySystem::display_info();
        cout << "Type: " << type_of_item << endl;
    }
};

// Basketball subclass
class Basketball : public IndoorSports {
private:
    string type_of_item;
public:
    Basketball(int productID, string name, float price, int amount_in_inventory, string type_of_item)
        : IndoorSports(productID, name, price, amount_in_inventory), type_of_item(type_of_item) {}

    void display_info() override {
        InventorySystem::display_info();
        cout << "Type: " << type_of_item << endl;
    }
};

// TableTennis subclass
class TableTennis : public IndoorSports {
private:
    string type_of_item;
public:
    TableTennis(int productID, string name, float price, int amount_in_inventory, string type_of_item)
        : IndoorSports(productID, name, price, amount_in_inventory), type_of_item(type_of_item) {}

    void display_info() override {
        InventorySystem::display_info();
        cout << "Type: " << type_of_item << endl;
    }
};

// Camping subclass
class Camping : public OutdoorSports {
private:
    string type_of_item;
public:
    Camping(int productID, string name, float price, int amount_in_inventory, string type_of_item)
        : OutdoorSports(productID, name, price, amount_in_inventory), type_of_item(type_of_item) {}

    void display_info() override {
        InventorySystem::display_info();
        cout << "Type: " << type_of_item << endl;
    }
};

// Soccer subclass
class Soccer : public OutdoorSports {
private:
    string type_of_item;
public:
    Soccer(int productID, string name, float price, int amount_in_inventory, string type_of_item)
        : OutdoorSports(productID, name, price, amount_in_inventory), type_of_item(type_of_item) {}

    void display_info() override {
        InventorySystem::display_info();
        cout << "Type: " << type_of_item << endl;
    }
};

// Golf subclass
class Golf : public OutdoorSports {
private:
    string type_of_item;
public:
    Golf(int productID, string name, float price, int amount_in_inventory, string type_of_item)
        : OutdoorSports(productID, name, price, amount_in_inventory), type_of_item(type_of_item) {}

    void display_info() override {
        InventorySystem::display_info();
        cout << "Type: " << type_of_item << endl;
    }
};

// Store class to manage products
class Store {
public:
    vector<InventorySystem*> products;

public:
    // Add product to store
    void add_product(InventorySystem* product) {
        products.push_back(product);
    }

    // Browse all products
    void browse_products() {
        cout << "Available Products:" << endl;
        for (auto& product : products) {
            product->display_info();
        }
    }

    // Search for a product by name
    void search_product(string name) {
        cout << "Searching for '" << name << "':" << endl;
        bool found = false;
        for (auto& product : products) {
            if (product->getProductID() == stoi(name)) {
                product->display_info();
                found = true;
            }
        }
        if (!found) {
            cout << "No products found." << endl;
        }
    }

    // Buy product by productID
    void buy_product(int productID, int quantity) {
        for (auto& product : products) {
            if (product->getProductID() == productID) {
                product->buy_item(quantity);
                return;
            }
        }
        cout << "Product not found." << endl;
    }

    // Restock product by productID
    void restock_product(int productID, int quantity) {
        for (auto& product : products) {
            if (product->getProductID() == productID) {
                product->restock_item(quantity);
                return;
            }
        }
        cout << "Product not found." << endl;
    }
};

// Main function for the User Interface
int main() {
    Store store;

    // Add products to the store
    store.add_product(new Volleyball(101, "Volleyball", 19.99, 10, "Ball"));
    store.add_product(new Volleyball(102, "Volleyball Net", 49.99, 5, "Net"));
    store.add_product(new Basketball(201, "Basketball", 29.99, 8, "Ball"));
    store.add_product(new TableTennis(301, "Table Tennis Paddle", 14.99, 20, "Paddle"));
    store.add_product(new Camping(401, "Camping Tent", 129.99, 3, "Tent"));
    store.add_product(new Soccer(501, "Soccer Cleats", 49.99, 15, "Cleats"));

    // User interface: Basic Menu
    int choice;
    while (true) {
        cout << "\n--- Store Menu ---" << endl;
        cout << "1. Browse Products" << endl;
        cout << "2. Search for Product by ID" << endl;
        cout << "3. Buy Product" << endl;
        cout << "4. Restock Product" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            store.browse_products();
        } else if (choice == 2) {
            string id;
            cout << "Enter product ID to search: ";
            cin >> id;
            store.search_product(id);
        } else if (choice == 3) {
            int productID, quantity;
            cout << "Enter product ID to buy: ";
            cin >> productID;
            cout << "Enter quantity: ";
            cin >> quantity;
            store.buy_product(productID, quantity);
        } else if (choice == 4) {
            int productID, quantity;
            cout << "Enter product ID to restock: ";
            cin >> productID;
            cout << "Enter quantity to restock: ";
            cin >> quantity;
            store.restock_product(productID, quantity);
        } else if (choice == 5) {
            cout << "Exiting the store..." << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    // Clean up dynamically allocated memory
    for (auto& product : store.products) {
        delete product;
    }

    return 0;
}
