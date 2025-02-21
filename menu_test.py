# menu_test.py

def main_menu():
    while True:
        print("\nMain Menu")
        print("1. Print a letter")
        print("2. Print a number")
        print("3. Quit")

        choice = input("\nEnter your choice (menu number): ").strip()

        if choice == "1":
            letter_function_menu()
        elif choice == "2":
            number_function_menu()
        elif choice == "3":
            print("\nExiting. Goodbye.")
            break
        else:
            print("\nInvalid choice. Please select a valid number.")

def letter_function_menu():
    while True:
        print("\nLetter Function Menu")
        print("1. Print a lowercase letter")
        print("2. Print an uppercase letter")
        print("3. Return to main menu")

        choice = input("\nEnter your choice (menu number): ").strip()

        if choice == "1":
            lowercase_letter_function()
        elif choice == "2":
            uppercase_letter_function()
        elif choice == "3":
            break  # Automatically returns to main_menu
        else:
            print("\nInvalid choice. Please select a valid number.")

def lowercase_letter_function():
    letter_to_print = input("\nEnter a lowercase or uppercase letter: ")
    letter_to_print = letter_to_print.lower()
    print(f"\nLowercase: {letter_to_print}")
    input("\nPress Enter to return to the menu...")

def uppercase_letter_function():
    letter_to_print = input("\nEnter a lowercase or uppercase letter: ")
    letter_to_print = letter_to_print.upper()
    print(f"\nUppercase: {letter_to_print}")
    input("\nPress Enter to return to the menu...")

def number_function_menu():
    while True:
        print("\nNumber Function Menu")
        print("1. Multiply number by 2")
        print("2. Square number")
        print("3. Return to main menu")

        choice = input("\nEnter your choice (menu number): ").strip()

        if choice == "1":
            multiply_number_by_two_function()
        elif choice == "2":
            square_number_function()
        elif choice == "3":
            break  # Automatically returns to main_menu
        else:
            print("\nInvalid choice. Please select a valid number.")

def multiply_number_by_two_function():
    try:
        number_to_multiply = float(input("\nEnter a number to multiply by 2: "))
        multiplied_number = number_to_multiply * 2
        print(f"\n{number_to_multiply} multiplied by 2 is: {multiplied_number}")
    except ValueError:
        print("\nInvalid input. Please enter a numeric value.")
    input("\nPress Enter to return to the menu...")

def square_number_function():
    try:
        number_to_square = float(input("\nEnter a number to square: "))
        squared_number = number_to_square ** 2
        print(f"\n{number_to_square} squared is: {squared_number}")
    except ValueError:
        print("\nInvalid input. Please enter a numeric value.")
    input("\nPress Enter to return to the menu...")

def main():
    main_menu()

if __name__ == "__main__":
    main()
