#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


int handValue = 0;

void printArray(int a[], int size);
int aceChecker(int aces);

int main(void) {
srand(time(NULL));


int deck[52];
int i;
for (i = 0; i < 52; i++) {
    deck[i] = i;
}

printArray(deck, 52);
int shufDeck[52] = {0};
int rnd, j = 0;

while (j < 52) {
    rnd = rand()%52;
    if (shufDeck[rnd] == 0) {
        shufDeck[rnd] = deck[j];
        j++;
    }
}
    printArray(shufDeck, 52);

int jj = 0;
int urhand[10] = {0};

while (jj < 2) {
    urhand[jj] = shufDeck[jj];
    jj++;
}
    printArray(urhand, 2);

int sizeofHand = 2;
int gameOver = 0;

int count = 0;
int value = 0;
int aces = 0;

while (count < sizeofHand) {
    value = ((urhand[count]/4) + 1);
    if (value == 1)
        aces++;
    if (value > 10)
        value = 10;
    printf("%d.\n", value);
    handValue = value + handValue;
    count++;
}
    SetConsoleOutputCP(CP_UTF8);
printf("Размер вашей руки составляет %d.\n\n", handValue);

if (aces > 0) {
    aceChecker(aces);
    aces = 0;
}

while (gameOver == 0) {
    char entry;
    printf("Ты хочешь ударить или остаться?\nДля удара нажмите H, для того чтобы остаться нажмите S.");
    scanf("%c", &entry);
    printf("\n");

    if (entry == 's' || entry == 'S') {
        gameOver = 1;
        printf("Ты решил завершить игру. Твой финальный результат составляет: %d.\n", handValue);
    }
    if (entry == 'h' || entry == 'H') {
        value = 0;
        sizeofHand++;
        printf("Карта: %d.\n", shufDeck[sizeofHand]);
        value = ((shufDeck[sizeofHand]/4) + 1);
        if (value > 10)
            value = 10;
        if (value == 1)
            aces++;
        if (aces > 0){
            aceChecker(aces);
            aces = 0;
        }
        printf("Сумма: %d.\n", value);
        handValue = handValue + value;
        printf("Сейчас сумма карт состаляет: %d. \n\n", handValue);
        printf("\n");
        entry = 'x';
    }
    if (handValue > 21) {
        printf("К сожалению ты проиграл. Сумма составляет: %d.\n", handValue);
        gameOver = 1;
    }
}
    return 0;
}

void printArray(int a[], int size) {
    int i;
    for (i = 0; i < size; i++) {
       printf("%d", a[i]);
    }
    printf("\n\n");
}

int aceChecker(int aces) {
    int i;
    printf("Вам выпал %d туз.\n", aces);
    for (i = 0; i < aces; i++) {
        int repeatNeeded = 1;
        char changeAce;
        printf("{Хотели бы вы, чтобы ваш туз считался 11, а не 1?\nНажмите Y, чтобы было Да или N, чтобы было Нет");
        while (repeatNeeded == 1) {
            scanf(" %c", &changeAce);
            if (changeAce == 'y' || changeAce == 'Y') {
                handValue = handValue + 10;
                repeatNeeded = 0;
            }
            if (changeAce == 'n' || changeAce == 'N')
                repeatNeeded = 0;
            if (repeatNeeded == 1)
                printf("Неверный ввод, пожалуйста повторите ещё раз. \n");
            }
            printf("Твое значение карт сейчас составляет: %d.\n\n", handValue);
        }
    return (0);
}