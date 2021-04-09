import random
import string

def generate_word(length : int):
    return ''.join(random.choice(string.ascii_lowercase + string.digits) for _ in range(length))

def main():
    number_of_words = 500
    number_of_tests = 50
    length_of_words = 5
    length_of_key = 2
    delimiter = ' '

    for _ in range(number_of_words):
        print(generate_word(length_of_words), end=delimiter)

    file = open('keys', 'w')

    file.write(str(number_of_tests))
    file.write('\n')

    for _ in range(number_of_tests):
        file.write(generate_word(random.randint(1, 5)))
        file.write(delimiter)

    file.close()

main()

