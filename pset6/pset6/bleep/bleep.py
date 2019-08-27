from sys import argv

def main():
    if len(argv) != 2:
        exit("Usage: python bleep.py dictionary")
    dictionary = open(argv[1]).read().split()
    original = input("What message would you like to censor?\n").split()
    bleeped = []
    for thing in range(len(original)):
        if original[thing].lower() in dictionary:
            bleeped.append(len(original[thing]) * '*')
        else:
            bleeped.append(original[thing])
    print(' '.join(bleeped))

if __name__ == "__main__":
    main()