#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//Teacher's Portal
class Assessment {
protected:
    float labAssessments[5] = {0}, labReports[5] = {0}, midterm = 0, cep = 0, finalTerm = 0;
public:
    virtual void inputMarks() = 0;
    virtual float calculateTotal() = 0;
};

class Student : public Assessment {
protected:
    string name, rollNumber;
    float totalMarks = 0, percentage = 0;
    char grade;
    float gpa;
public:
    void inputDetails() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
    }

    void inputMarks() override {
        cout << "Enter marks out of 15 for Lab Assessments:" << endl;
        for (int i = 0; i < 5; ++i) {
            cout << "  Lab Assessment " << i + 1 << ": ";
            cin >> labAssessments[i];
            if (labAssessments[i] > 15) labAssessments[i] = 15;
        }

        cout << "Enter marks out of 15 for Lab Reports:" << endl;
        for (int i = 0; i < 5; ++i) {
            cout << "  Lab Report " << i + 1 << ": ";
            cin >> labReports[i];
            if (labReports[i] > 15) labReports[i] = 15;
        }

        cout << "Enter marks out of 10 for CEP: ";
        cin >> cep;
        if (cep > 10) cep = 10;

        cout << "Enter marks out of 20 for Midterm: ";
        cin >> midterm;
        if (midterm > 20) midterm = 20;

        cout << "Enter marks out of 20 for Final Term: ";
        cin >> finalTerm;
        if (finalTerm > 20) finalTerm = 20;
    }

    float calculateTotal() override {
        float weights[] = {30, 25, 10, 15, 20};
        float labAssessmentTotal = 0, labReportTotal = 0;

        for (int i = 0; i < 5; ++i) {
            labAssessmentTotal += labAssessments[i];
            labReportTotal += labReports[i];
        }

        totalMarks = (labAssessmentTotal / 75) * weights[0] +
                     (labReportTotal / 75) * weights[1] +
                     (cep / 10) * weights[2] +
                     (midterm / 20) * weights[3] +
                     (finalTerm / 20) * weights[4];

        percentage = totalMarks;
        grade = calculateLetterGrade();
        gpa = calculateGPA();
        return totalMarks;
    }

    char calculateLetterGrade() {
        if (percentage >= 80) return 'A';
        else if (percentage >= 70) return 'B';
        else if (percentage >= 60) return 'C';
        else if (percentage >= 50) return 'D';
        return 'F';
    }

    float calculateGPA() {
        if (percentage >= 90) return 4.0;
        else if (percentage >= 80) return 3.5;
        else if (percentage >= 70) return 3.0;
        else if (percentage >= 60) return 2.5;
        else if (percentage >= 50) return 2.0;
        return 0.0;
    }

    friend ostream& operator<<(ostream& out, const Student& student) {
        out << "Name: " << student.name
            << ", Roll Number: " << student.rollNumber
            << ", Total Marks: " << student.totalMarks
            << ", Percentage: " << student.percentage
            << "%, Grade: " << student.grade
            << ", GPA: " << student.gpa << endl;
        return out;
    }
};

class Class : public Student {
private:
    string className;
    Student students[5];
    int studentCount;
public:
    void inputClassDetails() {
        cout << "Enter Class Name: ";
        cin.ignore();
        getline(cin, className);
    }

    void inputStudentDetails() {
        cout << "Enter number of students (max 5): ";
        cin >> studentCount;
        if (studentCount < 1 || studentCount > 5) {
            cout << "Invalid number of students!" << endl;
            return;
        }

        for (int i = 0; i < studentCount; ++i) {
            cout << "\nEntering details for student " << i + 1 << ":" << endl;
            students[i].inputDetails();
            students[i].inputMarks();
            students[i].calculateTotal();
        }
    }

    void displayResults() {
        cout << "\nClass: " << className << "\nResults:\n";
        for (int i = 0; i < studentCount; ++i) {
            cout << students[i];
        }
    }
};

//University Cafe
using namespace std;

struct MenuItem {
    string name;
    float price;
};

class Menu {
protected:
    MenuItem items[10]; 
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
    string cart[10]; 
    int quantities[10] = {0}; 

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

//Gaming Zone
class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

    void initializeBoard() {
        char pos = '1';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = pos++;
            }
        }
    }

    void displayBoard() {
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << " " << board[i][j] << " ";
                if (j < 2) cout << "|";
            }
            if (i < 2) cout << "\n---|---|---\n";
        }
        cout << "\n";
    }

    bool checkWin() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

        return false;
    }

    bool isDraw() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') return false;
            }
        }
        return true;
    }

public:
 
    TicTacToe() : currentPlayer('X') {
        initializeBoard();
    }

    void playGame() {
        int choice;
        bool gameRunning = true;

        while (gameRunning) {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter your position (1-9): ";
            cin >> choice;

            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;

            if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            board[row][col] = currentPlayer;

            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                gameRunning = false;
                break;
            }

            if (isDraw()) {
                displayBoard();
                cout << "The game is a draw!\n";
                gameRunning = false;
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
};

// Main Menu
int main() {
    int choice;
    string con;
    cout << "Welcome to the University Management System\n";
    do{
    cout << "1. Teacher's Portal\n";
    cout << "2. University Cafe\n";
    cout << "3. Gaming Zone\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            Class classObj;
            classObj.inputClassDetails();
            classObj.inputStudentDetails();
            classObj.displayResults();
            break;
        }
        case 2: {
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
            break;
        }
        case 3: {
        	TicTacToe game;
            game.playGame();
			break;
		}
        default:
            cout << "Invalid choice! Exiting...\n";
    }
    cout<<"Enter 'yes' if you want to continue uing program and 'no' if you want to exit the program\n";
    cin>>con;
}
while (con=="Yes" || con=="yes");

    return 0;
}

