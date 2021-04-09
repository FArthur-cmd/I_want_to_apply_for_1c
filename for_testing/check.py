import fileinput

file_list = []
key_list = []

with open('input.txt', "r") as f:
    for line in f:
        file_list.extend(line.split())

with open('keys', "r") as f:
    for line in f:
        key_list.extend(line.split())

def check_ans(text, key, ans):
    if ans == -1:
        return True

    for i, letter in enumerate(key):
        if letter != text[ans + i][i]:
            return False
    
    return True

for i, line in enumerate(fileinput.input()):
    ans = int(line)
    if (not check_ans(file_list, key_list[i + 1], ans)):
            print('Failed')
            print(key_list[i], ans)
            exit()

print('OK')

