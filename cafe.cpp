#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct MenuItem {
    string name;
    float price;
};

class Menu {
protected:
    MenuItem items[10]; // Menu items for the day (10 items for each day)
    string dayOfWeek;

    string getDayOfWeek() {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        return days[ltm->tm_wday];
    }

    void setMenuForDay() {
        dayOfWeek = getDayOfWeek();

        if (dayOfWeek == "Monday") {
            items[0] = {"Coffee", 100};
            items[1] = {"Donut", 50};
            items[2] = {"Sandwich", 150};
            items[3] = {"Cakes", 200};
            items[4] = {"Juice", 80};
            items[5] = {"Fries", 120};
            items[6] = {"Pizza", 250};
            items[7] = {"Pasta", 180};
            items[8] = {"Salad", 90};
            items[9] = {"Ice Cream", 60};
        } else if (dayOfWeek == "Tuesday") {
            items[0] = {"Tea", 80};
            items[1] = {"Croissant", 60};
            items[2] = {"Pasta", 200};
            items[3] = {"Muffin", 100};
            items[4] = {"Hot Dog", 150};
            items[5] = {"Burger", 180};
            items[6] = {"Smoothie", 130};
            items[7] = {"Salad", 90};
            items[8] = {"Soda", 70};
            items[9] = {"Waffle", 120};
        } else if (dayOfWeek == "Wednesday") {
            items[0] = {"Espresso", 120};
            items[1] = {"Bagel", 70};
            items[2] = {"Burger", 250};
            items[3] = {"Pasta", 150};
            items[4] = {"Fried Chicken", 200};
            items[5] = {"Cheesecake", 160};
            items[6] = {"Fries", 90};
            items[7] = {"Lemonade", 75};
            items[8] = {"Sandwich", 180};
            items[9] = {"Chocolate", 50};
        } else if (dayOfWeek == "Thursday") {
            items[0] = {"Latte", 130};
            items[1] = {"Brownie", 90};
            items[2] = {"Pizza Slice", 300};
            items[3] = {"Tacos", 200};
            items[4] = {"Smoothie", 140};
            items[5] = {"Pasta", 180};
            items[6] = {"Burger", 220};
            items[7] = {"Fries", 110};
            items[8] = {"Salad", 100};
            items[9] = {"Apple Pie", 150};
        } else if (dayOfWeek == "Friday") {
            items[0] = {"Mocha", 140};
            items[1] = {"Muffin", 100};
            items[2] = {"Wrap", 180};
            items[3] = {"Burger", 200};
            items[4] = {"Ice Cream", 80};
            items[5] = {"Pizza", 250};
            items[6] = {"Milkshake", 130};
            items[7] = {"Tacos", 180};
            items[8] = {"Cappuccino", 120};
            items[9] = {"Cookies", 70};
        } else if (dayOfWeek == "Saturday") {
            items[0] = {"Hot Chocolate", 150};
            items[1] = {"Cupcake", 80};
            items[2] = {"Taco", 220};
            items[3] = {"Ice Cream", 70};
            items[4] = {"Pizza", 280};
            items[5] = {"Fried Chicken", 180};
            items[6] = {"Fries", 90};
            items[7] = {"Burger", 250};
            items[8] = {"Smoothie", 100};
            items[9] = {"Brownie", 60};
        } else { // Sunday
            items[0] = {"Black Coffee", 90};
            items[1] = {"Cinnamon Roll", 110};
            items[2] = {"Salad", 170};
            items[3] = {"Fruit Salad", 150};
            items[4] = {"Sandwich", 200};
            items[5] = {"Wrap", 180};
            items[6] = {"Cheesecake", 160};
            items[7] = {"Soda", 60};
            items[8] = {"Pizza", 230};
            items[9] = {"Tea", 80};
        }
    }

public:
    void displayMenu() {
        setMenuForDay();
        cout << "\n*** Menu for " << dayOfWeek << " ***\n";
        for (int i = 0; i < 10; i++) {
            cout << items[i].name << ": Rs. " << items[i].price << endl;
        }
    }

    MenuItem* getMenu() {
        return items;
    }
};

class Order : public Menu {
protected:
    string cart[10]; // Cart array to store items
    int quantities[10] = {0}; // Quantities of each item in cart

public:
    void addToCart(string itemName) {
        bool found = false;
        for (int i = 0; i < 10; i++) {
            if (items[i].name == itemName) {
                cart[i] = itemName;
                quantities[i]++;
                found = true;
                cout << itemName << " added to your cart.\n";
                break;
            }
        }
        if (!found) {
            cout << "Invalid item! Please choose from the menu.\n";
        }
    }

    void removeFromCart(string itemName) {
        bool found = false;
        for (int i = 0; i < 10; i++) {
            if (cart[i] == itemName && quantities[i] > 0) {
                quantities[i]--;
                if (quantities[i] == 0) {
                    cart[i] = "";
                }
                found = true;
                cout << itemName << " removed from your cart.\n";
                break;
            }
        }
        if (!found) {
            cout << "Item not found in your cart.\n";
        }
    }

    void displayCart() {
        cout << "\nYour Order:\n";
        bool empty = true;
        for (int i = 0; i < 10; i++) {
            if (quantities[i] > 0) {
                cout << cart[i] << " x" << quantities[i] << " = Rs. " << items[i].price * quantities[i] << endl;
                empty = false;
            }
        }
        if (empty) {
            cout << "Your cart is empty.\n";
        }
    }

    float calculateTotal() {
        float total = 0;
        for (int i = 0; i < 10; i++) {
            total += items[i].price * quantities[i];
        }
        return total;
    }
};

class Billing : public Order {
public:
    void showBill() {
        float total = calculateTotal();
        float gst = total * 0.04;
        float finalBill = total + gst;

        cout << "\n***** Final Bill *****\n";
        displayCart();
        cout << "Subtotal: Rs. " << total << endl;
        cout << "GST (4%): Rs. " << gst << endl;
        cout << "Total: Rs. " << finalBill << endl;
        cout << "Thank you for visiting the University Cafe!\n";
    }
};

int main() {
    Billing cafe;
    string choice, itemName;
    bool shopping = true;

    while (shopping) {
        cafe.displayMenu();
        cout << "\nEnter 'Add' to add an item, 'Remove' to delete an item, or 'Bill' to show your final bill.\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == "Add" || choice == "add") {
            cout << "Enter the item name: ";
            cin.ignore();
            getline(cin, itemName);
            cafe.addToCart(itemName);
        } else if (choice == "Remove" || choice == "remove") {
            cout << "Enter the item name to remove: ";
            cin.ignore();
            getline(cin, itemName);
            cafe.removeFromCart(itemName);
        } else if (choice == "Bill" || choice == "bill") {
            cafe.showBill();
            shopping = false;
        } else {
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}

