from cs50 import get_int
while(True):
    num = get_int("Height: ")
    if(1<= num <= 8):
        break
numspaces = 1
for i in range(num, 0,-1):
    spaces = " " * (num-numspaces)
    blocks = "#" * (num-i+1)
    print(spaces, end="")
    print(blocks, end= "")
    print("  ", end="")
    print(blocks, end= "")
    print("")
    numspaces += 1