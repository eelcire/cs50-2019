def main():
    counter, firstDigit, secondDigit, odds, evens = 0, 0, 0, 0, 0
    card = int(input("Number: "))
    while card > 0:
        secondDigit = firstDigit
        firstDigit = card % 10
        if counter % 2 == 0:
            evens += firstDigit
        else:
            multiple = 2 * firstDigit
            odds += (multiple // 10) + (multiple % 10)
        card //= 10
        counter += 1

    isValid = (evens + odds) % 10 == 0
    doubleDigits = (firstDigit * 10) + secondDigit

    if firstDigit == 4 and 13 <= counter <= 16 and isValid:
        print("VISA\n")
    elif 51 <= doubleDigits <= 55 and counter == 16 and isValid:
        print("MASTERCARD\n")
    elif (doubleDigits == 34 or doubleDigits == 37) and counter == 15 and isValid:
        print("AMEX\n")
    else:
        print("INVALID\n")
main()