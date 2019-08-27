def main():
    stairs = int(input("Height? "))
    if 8 >= stairs > 0:
        for steps in range(1, stairs+1):
            print(" "*(stairs-steps), end = "")
            print("#"*(steps), end = "")
            print(" ", end = "")
            print("#"*(steps), end = "")
            print(" "*(stairs-steps))
main();