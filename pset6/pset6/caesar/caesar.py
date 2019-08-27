import sys
def main():
    if len(sys.argv) != 2:
        print("Usage: python caesar.py k")
        sys.exit(1)
    k = int(sys.argv[1])
    plaintext = input("plaintext: ")
    print("ciphertext: ", end = "")
    for thing in plaintext:
        if thing.isalpha == False:
            sys.exit(2)
        if thing.isupper:
            offset = 97
        else:
            offset = 65
        shift = ord(thing) - offset
        changed = (shift + k) % 26
        print(chr(changed + offset), end = "")
    print()
    return 0
main()