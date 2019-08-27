def main():
    stairs = int(input("Height? "))
    if stairs > 0:
        for steps in range(1, stairs+1):
            print(" "*(stairs-steps), end = "")
            print("#"*(steps))
        
main();
