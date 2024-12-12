from cs50 import get_int

def main():
    while True:
        answer = get_int("Height: ")
        if 1 <= answer <= 8:
            break
        else:
            print("You need to provide a number from 1 to 8.")

    blocks(answer)


def blocks(height):
    for row in range(height):
        # spaces
        for _ in range(height - (row + 1)):
            print(' ', end="")

        # blocks
        for _ in range(row + 1):
            print('#', end="")

        print()


# Launch the program
main()
