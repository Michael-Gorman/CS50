from cs50 import get_float

# Declare what each coins is worth
quarter = 25
dime = 10
nickel = 5
penny = 1

# Initiate change owed variable
change_owed = -1

# Get user input - keep asking while imput is not possitive
while (change_owed < 0):
    change_owed = get_float("change_owed:")
    cents = change_owed * 100

# Claculate min coins needed
quarters = cents // quarter
dimes = (cents % quarter) // dime
nickels = ((cents % quarter) % dime) // nickel
pennys = ((cents % quarter) % dime) % nickel

print(f"{int(quarters + dimes + nickels + pennys)}")
