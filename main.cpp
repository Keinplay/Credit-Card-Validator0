#include <iostream>
#include "Credit.h"

using namespace std;
int main() {
    string creditNumber;
    CreditCardValidator validator;
    do {
        cout << "Enter credit card number: ";
        cin >> creditNumber;

        validator.setCreditNumber(creditNumber);
        if(!validator.isValidNumber()){
            cout << "Enter a valid credit card number." << endl;
        }
    } while (!validator.isValidNumber());

    CreditCardType cardType = validator.getCardType();

    switch (cardType) {
        case AMERICAN_EXPRESS:
            cout << "American Express" << endl;
            break;
        case MASTER_CARD:
            cout << "MasterCard" << endl;
            break;
        case VISA:
            cout << "Visa" << endl;
            break;
        case INVALID:
            cout << "Unknown/Invalid card type" << endl;
            break;
    }

    return 0;
}
