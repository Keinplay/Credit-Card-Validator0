
#ifndef CREDIT_CREDIT_H
#define CREDIT_CREDIT_H
#include <string>
using namespace std;

enum CreditCardType {
    INVALID,
    AMERICAN_EXPRESS,
    MASTER_CARD,
    VISA
};
class CreditCardValidator {
public:
    CreditCardValidator();
    void setCreditNumber(const string &number);
    CreditCardType getCardType() const;
    bool isValidNumber() const;

private:
bool isValidDigits() const;
bool isValidStartingDigits() const;
bool isValidChecksum() const;
string creditNumber;
};

#endif //CREDIT_CREDIT_H