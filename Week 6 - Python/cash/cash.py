from cs50 import get_float

def main():
    while True:
        answer = get_float("Change: ")
        if answer > 0:
            break

    calculate_coins(answer)


def calculate_coins(cash):
    quarters = dimes = nickels = pennies = 0
    cash = cash * 100
    cash = int(cash)

    # Check for quarters
    if cash >= 25:
        quarters = int(cash / 25)
        cash = cash - quarters * 25

    # Check for dimes
    if 25 > cash >= 10:
        dimes = int(cash / 10)
        cash = cash - dimes * 10

    # Check for nickels
    if 10 > cash >= 5:
        nickels = int(cash / 5)
        cash = cash - nickels * 5

    # Check for pennies
    if 5 > cash >= 1:
        pennies = cash

    amount = quarters + dimes + nickels + pennies
    print(amount)


if __name__ == "__main__":
    main()
