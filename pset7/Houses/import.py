import csv, sys
from cs50 import SQL
db = SQL("sqlite:///students.db")
def main():
    csv_filename = import_csv(sys.argv)
    open_csv(csv_filename)


def import_csv(args):
    if len(args) != 2:
        print("Error")
        sys.exit(1)
    else:
        return args[1]


def open_csv(name):
    with open(name, "r") as csvfile:
        spamreader = csv.reader(csvfile, delimiter=' ', quotechar='|')
        next(spamreader, None)
        counter = 1
        for row in spamreader:
            hehe = ','.join(row)
            execute_query(hehe.split(","), counter)
            counter +=1
    csvfile.close()


def execute_query(data, id_num):
    first_name = data[0]
    if len(data) == 5:
        middle_name = data[1]
        last_name = data[2]
        house = data[3]
        birth = data[4]
    else:
        middle_name = None
        last_name = data[1]
        house = data[2]
        birth = data[3]
    values = ()
    db.execute("INSERT INTO students (first, middle, last, house, birth) Values (?,?,?,?,?)", first_name, middle_name, last_name, house, birth)

if __name__ == '__main__':
    main()