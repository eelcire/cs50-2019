import sys
import crypt


def main():
    if len(sys.argv) != 2:
        print("Usage: crack <hash>")
        sys.exit(1)

    hashh = sys.argv[1]
    salt = hashh[0:2]
    letters = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

    for fifth in letters:
        for fourth in letters:
            for third in letters:
                for second in letters:
                    for first in letters[1:]:
                        password = f"{first}{second}{third}{fourth}{fifth}".strip()

                        if crypt.crypt(candidate, salt) == ahash:
                            print(candidate)
                            sys.exit(0)
