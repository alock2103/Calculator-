#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float memory[5] = {0.0};

void choices() {
    printf("\nChoose The following Operators:\n");
    printf("B - Binary Operations\n");
    printf("U - Unary Operations\n");
    printf("A - advanced Operations\n");
    printf("V - Variable Memory\n");
    printf("E - Exit\n");
}

float Binary(float num1, char take, float num2) {
    printf("Binary Operations\n\n");
    switch (take) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0.0) {
                printf("denominator is zero\n");
                return 0.0;
            } else {
                return num1 / num2;
            }
        case '%':
            return fmod(num1, num2);
        case 'P':
            return pow(num1, num2);
        case 'X':
            return (num1 > num2) ? num1 : num2;
        case 'I':
            return (num1 < num2) ? num1 : num2;
        default:
            return 0.0;
    }
}

float Unary(char take, float num) {
    printf("Unary Operations\n");
    switch (take) {
        case 'S':
            return sqrt(num);
        case 'L':
            return log(num);
        case 'E':
            return exp(num);
        case 'C':
            return ceil(num);
        case 'F':
            return floor(num);
        default:
            printf("Invalid Input\n");
            return 0.0;
    }
}

void Memory(float x, char slot) {
    switch (slot) {
        case 'a':
            memory[0] = x;
            printf("Value of %c is %.2f\n", slot, x);
            break;
        case 'b':
            memory[1] = x;
            printf("Value of %c is %.2f\n", slot, x);
            break;
        case 'c':
            memory[2] = x;
            printf("Value of %c is %.2f\n", slot, x);
            break;
        case 'd':
            memory[3] = x;
            printf("Value of %c is %.2f\n", slot, x);
            break;
        case 'e':
            memory[4] = x;
            printf("Value of %c is %.2f\n", slot, x);
            break;
        default:
            printf("Invalid Input\n");
            break;
    }
}

float fetch(char slot) {
    switch (slot) {
        case 'a':
            return memory[0];
        case 'b':
            return memory[1];
        case 'c':
            return memory[2];
        case 'd':
            return memory[3];
        case 'e':
            return memory[4];
        default:
            return 0.0;
    }
}

int main() {
    char select;
    printf("Welcome to the calculator\n");
    do {
        choices();
        printf("Enter Your Choices: ");
        scanf(" %c", &select);

        switch (select) {
            case 'B':
                float x, y, result;
                char take;
                printf("type 1st number: ");
                scanf("%f", &x);
                printf("Enter Operand:");
                scanf(" %c", &take);
                printf("type 2nd number: ");
                scanf("%f", &y);
                result = Binary(x, take, y);
                printf("The answer is %.2f\n", result);
                break;

            case 'U':
                float num, res;
                char op;
                printf("Enter Operand: ");
                scanf(" %c", &op);
                printf("type a number:");
                scanf("%f", &num);
                res = Unary(op, num);
                printf("the answer is %.2f\n", res);
                break;

            case 'V':
                char slot;
                float value;
                printf("enter memory slots (a/b/c/d/e): ");
                scanf(" %c", &slot);
                if (slot < 'a' || slot > 'e') {
                    printf("Invalid memory slot\n");
                    break;
                }
                printf("Enter a value for %c: ", slot);
                scanf("%f", &value);
                Memory(value, slot);
                break;

            case 'A':
                char sub;
                printf("Advanced Operations\n");
                printf("\nChoose The following Operators:\n");
                printf("B - Binary Operations\n");
                printf("U - Unary Operations\n");
                printf("E - Exit\n");
                scanf(" %c", &sub);
                if (sub == 'E') {
                    break;
                }
                float num1, num2, res;
                char take;
                if (sub == 'B') {
                    char x1, x2;
                    printf("Enter the first variable (a/b/c/d/e): ");
                    scanf(" %c", &x1);
                    num1 = (x1 >= 'a' && x1 <= 'e') ? memory[x1 - 'a'] : x1 - '0';
                    printf("Enter Operand: ");
                    scanf(" %c", &take);
                    printf("Enter the second variable (a/b/c/d/e): ");
                    scanf(" %c", &x2);
                    num2 = (x2 >= 'a' && x2 <= 'e') ? memory[x2 - 'a'] : x2 - '0';

                    res = Binary(num1, take, num2);
                    printf("The answer is %.2f\n", res);
                } else if (sub == 'U') {
                    char var;
                    printf("enter variable (a/b/c/d/e): ");
                    scanf(" %c", &var);
                    num1 = (var >= 'a' && var <= 'e') ? memory[var - 'a'] : var - '0';
                    printf("Enter Operand: ");
                    scanf(" %c", &take);
                    res = Unary(take, num1);
                    printf("The answer is %.2f\n", res);
                } else {
                    printf("Invalid input\n");
                }
                break;

            case 'E':
                printf("Goodbye\n");
                break;

            default:
                printf("Invalid Input\n");
        }
    } while (select != 'E');
    return 0;
}
