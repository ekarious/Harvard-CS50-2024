def main():
    answer = input("Text: ")
    text = Text(answer)
    text.grade()

class Text:
    def __init__(self, raw) -> None:
        self.text = raw
        self.letters = 0
        self.words = 0
        self.sentences = 0
        self.note = None

        self.analyze_text()
        self.calculate_index()

    def __len__(self) -> int:
        return len(self.text)

    def __str__(self) -> str:
        return f"letters: {self.letters} / words: {self.words} / sentences: {self.sentences} / grade: {self.note}"

    def analyze_text(self):
        for letter in self.text:
            if letter.isalpha():
                self.letters += 1
            elif letter == " ":
                self.words += 1
            elif letter == '.' or letter == '?' or letter == '!':
                self.sentences += 1

        # we need to add the last word
        self.words += 1

    def calculate_index(self):
        l = self.letters / self.words * 100
        s = self.sentences / self.words * 100

        self.note = round(0.0588 * l - 0.296 * s - 15.8)

    def grade(self) -> str:
        if self.note < 1:
            print("Before Grade 1")
        elif self.note >= 16:
            print("Grade 16+")
        else:
            print(f"Grade {self.note}")


if __name__ == "__main__":
    main()
