/* Elix0r
 * 10/20/2020
 *
 * This is a cashier program to take a customer's order of bottles and apply the correct discounts and output the
 * correct price for the order. Also outputs sale info to a receipt text file
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
// Variables
    double bottlePrice = 24.00;
    double totalSale;
    double actSale;
    int totalBottles;
    int maxAmount = 399;
    int minAmount = 0;
    int firstDiscountRange = 11;
    int secondDiscountRange = 16;
    int thirdDiscountRange = 21;
    int fourthDiscountRange = 31;
    double firstDiscountAmount = 10.00;
    double secondDiscountAmount = 20.00;
    double thirdDiscountAmount = 30.00;
    double fourthDiscountAmount = 35.00;
    double amountSaved;
    int discountUsed;
    string GoAgain;
    ofstream outFS;

    // Do-while loop to repeat program if user enters "Y" or "Yes" at the bottom of program
    do {
        // General output for user about prices and discounts
        cout << "Welcome to the Winslow Glass Bottle Shop" << endl << "We sell bottles that cost $24 each" << endl;
        cout << "You can only purchase 0 to 399 bottles at one time. We offer discounts for the amount of bottles purchased." << endl;
        cout << "The discounts are: " << endl;
        cout << "11-15: 10% Off the total order" << endl;
        cout << "16-20: 20% Off the total order" << endl;
        cout << "21-30: 30% Off the total order" << endl;
        cout << "31 and up: 35% Off the total order" << endl << endl << "How many bottles would you like to purchase?: " << endl;

        cin >> totalBottles; //Input from user
        totalSale = totalBottles * bottlePrice; // Calculation for price of bottles

        // While loop to make sure user input is within the range 0-399. Outputs message to user to enter acceptable amount
        while (totalBottles < minAmount || totalBottles > maxAmount) {
            cout << "The amount you entered is outside the range of 0 to 399 bottles" << endl;
            cout << "Please enter a number within that range: " << endl;
            cin >> totalBottles;
        }

        // Nested if statements to check amount of bottles purchased and apply correct discount
        if (totalBottles >= firstDiscountRange && totalBottles < secondDiscountRange) {
            amountSaved = totalSale / firstDiscountAmount;
            actSale = totalSale - totalSale / firstDiscountAmount;
            discountUsed = 10;
        } else if (totalBottles >= secondDiscountRange && totalBottles < thirdDiscountRange) {
            amountSaved = totalSale / secondDiscountAmount;
            actSale = totalSale - totalSale / secondDiscountAmount;
            discountUsed = 20;
        } else if (totalBottles >= thirdDiscountRange && totalBottles < fourthDiscountRange) {
            amountSaved = totalSale / thirdDiscountAmount;
            actSale = totalSale - totalSale / thirdDiscountAmount;
            discountUsed = 30;
        } else if (totalBottles >= fourthDiscountRange) {
            amountSaved = totalSale / fourthDiscountAmount;
            actSale = totalSale - totalSale / fourthDiscountAmount;
            discountUsed = 35;
        } else {
            amountSaved = 0.00;
            discountUsed = 0;
            actSale = totalSale;
        }

        // Output sale info for user. Fixed and precision attributes to correctly format output
        cout << "Price before discount: " << fixed << setprecision(2) << "$" << totalSale << endl;
        cout << "Discount percentage: " << discountUsed << "%" << endl;
        cout << "Amount saved in discount: " << fixed << setprecision(2) << "$" << amountSaved << endl;
        cout << "Price after discount: " << fixed << setprecision(2) << "$" << actSale << endl << endl;
        cout << "Would you like to run the program again? Yes/No " << endl;

        // Opening of receipt file in appending mode
        outFS.open("SaleReceipt.txt", fstream::app);

        // Same sale output to receipt file but with a bar to separate transactions
        outFS << "Order: " << endl;
        outFS << "====================================================" << endl;
        outFS << "Price before discount: " << fixed << setprecision(2) << "$" << totalSale << endl;
        outFS << "Discount percentage: " << discountUsed << "%" << endl;
        outFS << "Amount saved in discount: " << fixed << setprecision(2) << "$" << amountSaved << endl;
        outFS << "Price after discount: " << fixed << setprecision(2) << "$" << actSale << endl << endl;
        outFS.close();

        // taking user input to go again
        cin >> GoAgain;

    } while (GoAgain == "Y" or GoAgain == "y" or GoAgain =="Yes" or GoAgain == "yes");
    return 0;
}
