from cs50 import get_string
import re
def main():
    words = 1
    letters = 0
    sentences = 0
    text = get_string("Text: ")
    if re.search("[a-z]|[A-Z]", text):
        letters += len(re.findall("[a-z]|[A-Z]", text))
    if re.search(" ", text):
        words += len(re.findall(" ", text))
    if re.search("\.|!|\?", text):
        sentences += len(re.findall("\.|!|\?", text))
    words /= 100
    letters /= words
    sentences /= words
    grade = (0.0588 * letters) - (0.296 * sentences) - 15.8
    if grade >= 16:
        print("Grade 16+")
    elif grade < 1:
        print("Before Grade 1")
    else:
        print(grade)
        print("Grade", round(grade))
main()