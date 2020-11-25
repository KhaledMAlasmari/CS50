from cs50 import get_string
import re
def credit():
    credit_card = get_string("Number:")
    length = len(credit_card)
    if(luhan(credit_card, length)):
        ccType(credit_card, length)
    else:
        print("INVALID")


def luhan(ccNum, length):
    length = (length * -1) - 1
    checkSum = 0
    for i in range(-1, length, -1):
        if i % 2 == 1:
            checkSum += int(ccNum[i])
        else:
            num = str(int(ccNum[i]) *2)
            for j in num:
                checkSum += int(j)
    if(str(checkSum)[1] == "0"):
        return True


def ccType(ccNum, length):
    if(length == 15 and re.search("^3(4|7)",ccNum)):
        print("AMEX")
    elif(length == 16 and re.search("^5(1|2|3|4|5)", ccNum)):
        print("MASTERCARD")
    elif ((length == 13 or length == 16) and re.search("^4", ccNum)):
        print("VISA")
    else:
        print("INVALID")
credit()