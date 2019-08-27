def main():
    munny = float(input("Change Owed: "))
    money = munny * 100
    counter = 0
    while money >= 25:
        money -= 25
        counter += 1
    while money >= 10:
        money -= 10
        counter += 1
    while money >= 5:
        money -= 5
        counter += 1
    while money >= 1:
        money -= 1
        counter += 1
    print(counter)
main()