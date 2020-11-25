import sys, csv, re
def main():
    checkArgs(sys.argv)
    database, sequence = readFiles(sys.argv[1], sys.argv[2])
    labels, database = parseDatabase(database)
    searchDatabase(database, sequence, labels)

def checkArgs(argv):
    if(len(argv) != 3):
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

def readFiles(database, sequence):
    file = open(sequence, 'r')
    sequence = ""
    for i in file:
        sequence+= i
    with open(database, newline='') as csvfile:
        rows = csv.reader(csvfile, delimiter=',', quotechar='"')
        database = []
        for row in rows:
            database.append([x for x in row])
    return database, sequence



def parseDatabase(database):
    labels = [labels for labels in database[0][1:]]
    database.pop(0)
    return labels, database





def searchDatabase(database, sequence, labels):
    lengthDatabase = len(database)
    #for each user, check each given STR
    for i in range(lengthDatabase):
        user = [database[i][0]]
        for j in range(1,len(database[i])):
            personRepeatsNumber = database[i][j]
            STR = labels[j-1]
            numOfRepeats = searchSequence(STR, sequence)
            if int(numOfRepeats) == int(personRepeatsNumber):
                user.append(personRepeatsNumber)
        if(len(user) == len(labels)+1):
            print(user[0])
            sys.exit(0)
    print("No match")
    sys.exit(0)



def searchSequence(pattern, sequence):
    patternLength = len(pattern)
    sequenceLength = len(sequence)
    numberOfRepeats = [x*0 for x in range(sequenceLength)]
    # for each letter check whether the next letters (including it) matches the given pattern
    for i in range(sequenceLength):
        start = i
        for j in range(patternLength,sequenceLength,patternLength):
            if sequence[start:patternLength + start] == pattern:
                numberOfRepeats[i]+= 1
                start += patternLength
            else:
                break
    # sort the array and return the highest number
    numberOfRepeats = sorted(numberOfRepeats)
    return numberOfRepeats[-1]



if __name__ == "__main__":
    main()
