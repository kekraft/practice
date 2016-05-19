#!/usr/bin/env python

# Generate powerset from a list, actually return a list

def powerset(given_list):
    if len(given_list < 1):
        yield []
    else:
        for item in powerset(given_list[1:]):
            yield [seq[0]] + item
            yield item

if __name__ = "__main__":
    a = [1,3,4,5,6,2324,97,32,-1,3,4]
    
    print powerset(a)

