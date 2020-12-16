import sys
from cs50 import SQL
db = SQL("sqlite:///students.db")
def main():
    house = get_house(sys.argv)
    execute_query(house)

def get_house(args):
    if len(args) != 2:
        print("Error")
        sys.exit(1)
    else:
        return args[1]

def execute_query(house):
    values = (house)
    hehe = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", values)
    for i in hehe:
        middle = ' ' if i['middle'] == None else " " + i['middle'] + " "
        print(i['first'] + middle + i['last'] + ', ' + 'born ' + str(i['birth']))
if __name__ == '__main__':
    main()