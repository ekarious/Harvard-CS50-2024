def main():
    answer = input("Number: ")
    card = Card(answer)
    if card.is_valid():
        card.show()
    else:
        print("INVALID")


class Card:

    def __init__(self, card_number) -> None:
        self.card_number = card_number
        self.card_length = len(self.card_number)
        self.card_type = self.check_card_type()
        self.is_checksum_valid = self.checksum()

    def __len__(self) -> int:
        return len(self.card_number)

    def __str__(self):
        return f'CARD: {self.card_number} / checksum: {self.is_checksum_valid} / type: {self.card_type} / Length: {self.card_length}'

    def check_card_type(self) -> str:
        if self.card_number[:1] == '4':
            return "VISA"
        elif '51' <= self.card_number[:2] <= '55':
            return "MASTERCARD"
        elif self.card_number[:2] == '34' or self.card_number[:2] == '37':
            return "AMEX"
        else:
            return "INVALID"

    def checksum(self) -> bool:
        sum_even = 0
        sum_odd = 0

        for i, digit in enumerate(reversed(self.card_number)):
            digit = int(digit)

            # if even (i starts at 0)
            if i % 2 == 1:
                doubled = digit * 2
                sum_even += (doubled % 10 + doubled // 10)
            else:
                sum_odd += digit

        total = sum_even + sum_odd
        return total % 10 == 0

    def is_valid(self) -> bool:
        # We check this first
        if self.is_checksum_valid == False:
            return False

        if self.card_length == 15 and self.card_type == "AMEX":
            return True

        if self.card_length == 16 and self.card_type == "VISA":
            return True

        if self.card_length == 16 and self.card_type == "MASTERCARD":
            return True

        if self.card_length == 13 and self.card_type == "VISA":
            return True

        return False

    def show(self):
        print(self.card_type)


if __name__ == "__main__":
    main()
