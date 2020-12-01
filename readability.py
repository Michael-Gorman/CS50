from cs50 import get_string

t = get_string("Text:")
l = 0
s = 0

# Letter counter:
#loop through string text, if character is in alphabet, add to counter
for char in range(len(t)):
    if (t[char].isalpha()):
        l += 1

# Word counter:
w = len(t.split())

# Sentence counter:
#loop through string (text), if character is end of sentence('.','!','?') add to counter
for char in range(len(t)):
    if (t[char] == '.' or t[char] == '?' or t[char] == '!'):
        s += 1

# Index Calc:
# Calculate ratio of words in text to 100 words
w_ratio = 100 / w
# Calculate average letters per 100 words
l_ave = l * w_ratio
#Calculate average sentences per 100 words
s_ave = s * w_ratio

# Colman-Liau formula using calculated values
index = (0.0588 * l_ave) - (0.296 * s_ave) - 15.8

# Round the index to an int
grade = round(index)

# Print the reading Grade of the text
if (grade >= 16):
    print("Grade 16+")
elif (grade < 1):
    print("before Grade 1")
elif (1 <= grade < 16):
    print(f"Grade {grade}")
