#include <iostream>
#include <cctype>
#include <string>
#include "Credit.h"
using namespace std;

CreditCardValidator::CreditCardValidator() : creditNumber("") {}

void CreditCardValidator::setCreditNumber(const std::string &number) {
    creditNumber = number;
}

CreditCardType CreditCardValidator::getCardType() const {
    if (isValidStartingDigits()) {
        char firstDigit = creditNumber[0];
        if (firstDigit == '3' && (creditNumber[1] == '4' || creditNumber[1] == '7')) {
            return AMERICAN_EXPRESS;
        } else if (firstDigit == '5' && creditNumber[1] >= '1' && creditNumber[1] <= '5') {
            return MASTER_CARD;
        } else if (firstDigit == '4') {
            return VISA;
        }
    }
    return INVALID;
}

bool CreditCardValidator::isValidNumber() const{
    return isValidDigits() && isValidStartingDigits() && isValidChecksum();
}

bool CreditCardValidator::isValidDigits() const {
    for(char digit: creditNumber) {
        if (!isdigit(digit)) {
            return false;
        }
    }
    int length = creditNumber.length();
    return (length >= 13 && length <= 16);
}

bool CreditCardValidator::isValidStartingDigits() const {
    if (creditNumber.length() < 1) {
        return false;
    }

    char firstDigit = creditNumber[0];

    // American Express: 34 or 37
    if (firstDigit == '3' && (creditNumber[1] == '4' || creditNumber[1] == '7')) {
        return true;
    }
        // MasterCard: 51, 52, 53, 54, or 55
    else if (firstDigit == '5' && creditNumber[1] >= '1' && creditNumber[1] <= '5') {
        return true;
    }
        // Visa: 4
    else if (firstDigit == '4') {
        return true;
    }

    return false;
}

bool CreditCardValidator::isValidChecksum() const {
    int sum = 0;
    int length = creditNumber.length();

    for (int i = length - 2; i >= 0; i -= 2) {
        int digit = (creditNumber[i] - '0') * 2;
        sum += digit % 10 + digit / 10;
    }
    for(int i = length - 1; i >= 0; i -= 2) {
        sum += creditNumber[i] - '0';
    }
    return(sum % 10 == 0);
}