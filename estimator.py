import string
import itertools
import time


#no va :>
def estimate_bruteforce_time(password, charset, att_speed):
    set_size = len(charset)
    total_attempts = 0

    for i in range(1, len(password)):
        total_attempts += set_size ** i

    for i in range(len(password) - 1, 0, -1):
        total_attempts += set_size ** len(password) * charset.find(password[i])
    seconds = total_attempts / att_speed
    return seconds

def main():
    input_file = input("Enter the path to the input file: ")
    output_file = input("Enter the path to the output file: ")
    
    charset_choice = input("Choose character set (numbers/lowercase/all): ")
    if charset_choice == "numbers":
        charset = string.digits
    elif charset_choice == "lowercase":
        charset = string.ascii_lowercase
    elif charset_choice == "all":
        charset = string.printable
    else:
        print("Invalid character set choice. Exiting.")
        return

    att_speed = float(input("Enter the attempt speed (attempts per second): "))

    with open(input_file, 'r') as infile, open(output_file, 'w') as outfile:
        for line in infile:
            password = line.strip()
            seconds = estimate_bruteforce_time(password, charset, att_speed)
            outfile.write(f"{password},{seconds}\n")

    print("Results written to", output_file)

if __name__ == "__main__":
    main()
