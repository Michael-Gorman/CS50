from sys import argv, exit
import csv

# A program that identifies a person based on their DNA, by comparing a sequence with a csv file

# Comand-line arguments Check - checking for the correct number of arguments.
if (len(argv) != 3):
    print("Error:  Incorrect number of command-line arguments.\n\tUsage: python dna.py data.csv sequence.txt")
    exit(1)
else:
    pass

# First arg should be CSV, second should be txt
data = csv.reader(open(argv[1]))    # Open the database csv file,  Reads the csv file to lines
database = [row for row in data]    # Converts the data file to a list of lists (2D list)

with open(argv[2]) as dna_sample:   # Opens sequence txt file and returns a string
    dna = dna_sample.read()

counts = []     # Declares list that counts the amount of consecutive STRs

for i in range(1, len(database[0])):    # Loop through top row of database to get STRs (start range at 1 to exclude the 'name' header)
    count = 1                           # Initalise a count of consec STRs. start at 1 for the first.
    string = database[0][i]             # Assign a STR to string
    while string * count in dna:        # While the STR * the  current count is in the dna
        count += 1                      # Add oone to the current count
    counts.append(str(count - 1))       # Append the counts list with the highest count of each STR

for j in range(1, len(database)):                   # Loop through all rows in database file (still starting at 1 to exclude names)

    if database[j][1:len(database[0])] == counts:   # Compare only the numbers in each row of the database (each persons set of STR counts) to the 'counts' list
        print(database[j][0])                       # Print the corresponding name by priting the first position in that row
        exit(0)                                     # Exit program if match is found

print('No Match')   # Print 'No Match' if no match has been found.
