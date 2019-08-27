from nltk import sent_tokenize

def lines(a, b):
    """Return lines in both a and b"""
    c = []
    asplit = set(a.split("\n"))
    bsplit = set(b.split("\n"))
    for thing in asplit:
        if thing in bsplit:
            c.append(thing)
    return c


def sentences(a, b):
    """Return sentences in both a and b"""
    c = []
    asplit = set(sent_tokenize(a))
    bsplit = set(sent_tokenize(b))
    for thing in asplit:
        if thing in bsplit:
            c.append(thing)
    return c

def thong(string, n):
    thongs = []
    for thing in range(len(string) - n + 1):
        thongs.append(string[thing:thing+n])
    return thongs

def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    c = []
    asplit = set(thong(a, n))
    bsplit = set(thong(b, n))
    for thing in asplit:
        if thing in bsplit:
            c.append(thing)
    return c
