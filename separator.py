import re
import random
from urllib import request

def download_raw_text(url):
    response = request.urlopen(url)
    data = response.read().decode('utf-8')
    return data

def separate_strings_by_char_sets(raw_text):
    numbers_set = re.compile(r'^\d+$', re.MULTILINE)
    lowercase_set = re.compile(r'^[a-z]+$', re.MULTILINE)

    numbers = numbers_set.findall(raw_text)
    lowercase = lowercase_set.findall(raw_text)
    all_characters = [string for string in raw_text.split('\n') if string]

    return numbers, lowercase, all_characters

def write_to_files(numbers, lowercase, all_characters, n):
    selected_numbers = random.sample(numbers, min(n, len(numbers)))
    selected_lowercase = random.sample(lowercase, min(n, len(lowercase)))
    selected_all_characters = random.sample(all_characters, min(n, len(all_characters)))

    with open('numbers.txt', 'w') as numbers_file:
        numbers_file.write('\n'.join(selected_numbers))

    with open('lowercase.txt', 'w') as lowercase_file:
        lowercase_file.write('\n'.join(selected_lowercase))

    with open('all_characters.txt', 'w') as all_characters_file:
        all_characters_file.write('\n'.join(selected_all_characters))

if __name__ == "__main__":
    url = input("Enter the raw URL: ")
    raw_text = download_raw_text(url)

    numbers, lowercase, all_characters = separate_strings_by_char_sets(raw_text)

    n = int(input("Enter the maximum number of strings to write: "))
    write_to_files(numbers, lowercase, all_characters, n)

    print(f"Files created successfully: numbers.txt, lowercase.txt, all_characters.txt (random {min(n, len(all_characters))} strings from each set)")