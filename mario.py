from cs50 import get_int


height = 0

while(height < 1 or height > 8):
    height = get_int("Height:")
    
for y in range(1, height + 1):
    space = " " * (height - y)
    block = "#" * y
    print(f"{space}{block}")
