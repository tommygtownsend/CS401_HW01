class InventorySystem:
    def __init__(self, productID, name, price, amount_in_inventory):
        self.productID = productID
        self.name = name
        self.price = price
        self.amount_in_inventory = amount_in_inventory

    def display_info(self):
        print(f"Product ID: {self.productID}, Name: {self.name}, Price: ${self.price:.2f}, Available: {self.amount_in_inventory}")
    
    def buy_item(self, quantity):
        """Handle the purchase of a certain quantity of an item."""
        if self.amount_in_inventory >= quantity:
            self.amount_in_inventory -= quantity
            print(f"Purchased {quantity} {self.name}(s).")
        else:
            print(f"Not enough stock for {self.name}. Only {self.amount_in_inventory} available.")
    
    def restock_item(self, quantity):
        """Restock the item if necessary."""
        self.amount_in_inventory += quantity
        print(f"Restocked {quantity} {self.name}(s). Now available: {self.amount_in_inventory}.")

class IndoorSports(InventorySystem):
    def __init__(self, productID, name, price, amount_in_inventory):
        super().__init__(productID, name, price, amount_in_inventory)

class OutdoorSports(InventorySystem):
    def __init__(self, productID, name, price, amount_in_inventory):
        super().__init__(productID, name, price, amount_in_inventory)

class Volleyball(IndoorSports):
    def __init__(self, productID, name, price, amount_in_inventory, type_of_item):
        super().__init__(productID, name, price, amount_in_inventory)
        self.type_of_item = type_of_item

    def display_info(self):
        super().display_info()
        print(f"Type: {self.type_of_item}")

class Basketball(IndoorSports):
    def __init__(self, productID, name, price, amount_in_inventory, type_of_item):
        super().__init__(productID, name, price, amount_in_inventory)
        self.type_of_item = type_of_item

    def display_info(self):
        super().display_info()
        print(f"Type: {self.type_of_item}")

class TableTennis(IndoorSports):
    def __init__(self, productID, name, price, amount_in_inventory, type_of_item):
        super().__init__(productID, name, price, amount_in_inventory)
        self.type_of_item = type_of_item

    def display_info(self):
        super().display_info()
        print(f"Type: {self.type_of_item}")

class Camping(OutdoorSports):
    def __init__(self, productID, name, price, amount_in_inventory, type_of_item):
        super().__init__(productID, name, price, amount_in_inventory)
        self.type_of_item = type_of_item

    def display_info(self):
        super().display_info()
        print(f"Type: {self.type_of_item}")

class Soccer(OutdoorSports):
    def __init__(self, productID, name, price, amount_in_inventory, type_of_item):
        super().__init__(productID, name, price, amount_in_inventory)
        self.type_of_item = type_of_item

    def display_info(self):
        super().display_info()
        print(f"Type: {self.type_of_item}")

class Golf(OutdoorSports):
    def __init__(self, productID, name, price, amount_in_inventory, type_of_item):
        super().__init__(productID, name, price, amount_in_inventory)
        self.type_of_item = type_of_item

    def display_info(self):
        super().display_info()
        print(f"Type: {self.type_of_item}")

class Store:
    def __init__(self):
        self.products = []  # List of all products in the store
    
    def add_product(self, product):
        self.products.append(product)
    
    def browse_products(self):
        print("Available Products:")
        for product in self.products:
            product.display_info()
    
    def search_product(self, name):
        print(f"Searching for '{name}':")
        found = False
        for product in self.products:
            if name.lower() in product.name.lower():
                product.display_info()
                found = True
        if not found:
            print("No products found.")
    
    def buy_product(self, productID, quantity):
        for product in self.products:
            if product.productID == productID:
                product.buy_item(quantity)
                return
        print("Product not found.")
    
    def restock_product(self, productID, quantity):
        for product in self.products:
            if product.productID == productID:
                product.restock_item(quantity)
                return
        print("Product not found.")

# Create the store
store = Store()

# Add products to the store
store.add_product(Volleyball(101, "Volleyball", 19.99, 10, "Ball"))
store.add_product(Volleyball(102, "Volleyball Net", 49.99, 5, "Net"))
store.add_product(Basketball(201, "Basketball", 29.99, 8, "Ball"))
store.add_product(TableTennis(301, "Table Tennis Paddle", 14.99, 20, "Paddle"))
store.add_product(Camping(401, "Camping Tent", 129.99, 3, "Tent"))
store.add_product(Soccer(501, "Soccer Cleats", 49.99, 15, "Cleats"))

# User interface: Basic Menu
while True:
    print("\n--- Store Menu ---")
    print("1. Browse Products")
    print("2. Search for Product")
    print("3. Buy Product")
    print("4. Restock Product")
    print("5. Exit")
    choice = input("Enter your choice: ")
    
    if choice == "1":
        store.browse_products()
    elif choice == "2":
        name = input("Enter product name to search: ")
        store.search_product(name)
    elif choice == "3":
        productID = int(input("Enter product ID to buy: "))
        quantity = int(input("Enter quantity: "))
        store.buy_product(productID, quantity)
    elif choice == "4":
        productID = int(input("Enter product ID to restock: "))
        quantity = int(input("Enter quantity to restock: "))
        store.restock_product(productID, quantity)
    elif choice == "5":
        print("Exiting the store...")
        break
    else:
        print("Invalid choice. Please try again.")
