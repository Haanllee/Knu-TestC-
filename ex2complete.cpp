#include <iostream>
#include <fstream>

using namespace std;
// Definition of product structure 
struct Product {
    char code[16];
    char productName[51];
    float price;
    int quantity;
};

int main() {
    int n;
    cout << "Enter product quantity: ";
    cin >> n;
    Product products[n];
    // Enter product information
    for (int i = 0; i < n; ++i) {
        cout << "Enter product information number " << i + 1 << ":" << endl;
        cout << "Code: ";
        cin >> products[i].code;
        cout << "Product Name: ";
        cin.ignore();  // Clear the newline character from the buffer
        cin.getline(products[i].productName, 51);
        cout << "Price: ";
        cin >> products[i].price;
        cout << "Quantity: ";
        cin >> products[i].quantity;
    }
    // Check if any product has a quantity greater than 10
    bool hasProductsGreaterThan10 = false;
    for (int i = 0; i < n; ++i) {
        if (products[i].quantity > 10) {
            hasProductsGreaterThan10 = true;
            break;
        }
    }
    // Show products with quantity greater than 10 or notify if there are none
    if (hasProductsGreaterThan10) {
        cout << "\nProducts with quantities greater than 10:" << endl;
        for (int i = 0; i < n; ++i) {
            if (products[i].quantity > 10) {
                cout << "Code: " << products[i].code << endl;
                cout << "Product Name: " << products[i].productName << endl;
                cout << "Price: " << products[i].price << endl;
                cout << "Quantity: " << products[i].quantity << endl << endl;
            }
        }
        // Save file Quantity10.txt
        ofstream outFile("Quantity10.txt");
        if (outFile.is_open()) {
            for (int i = 0; i < n; ++i) {
                if (products[i].quantity > 10) {
                    outFile << "Code: " << products[i].code << endl;
                    outFile << "Product Name: " << products[i].productName << endl;
                    outFile << "Price: " << products[i].price << endl;
                    outFile << "Quantity: " << products[i].quantity << endl << endl;
                }
            }
            cout << "Lists of products with quantities greater than 10 are saved to the file Quantity10.txt!" << endl;
            outFile.close();
        } else {
            cout << "Cannot open Quantity10.txt file to record data." << endl;
        }
    } else {
        cout << "There are no products with quantities greater than 10!" << endl;
        cout << "Cannot save text file because there is no product greater than 10." << endl;
    }

    return 0;
}

