#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float memory[5] = {0.0};

void choices() {
    printf("\nChoose The following Operators:\n");
    printf("B - Binary Operations\n");
    printf("U - Unary Operations\n");
    printf("A - Advanced Operations\n");
    printf("V - Variable Memory\n");
    printf("I - Integration\n");
    printf("D - Differentiation\n");
    printf("E - Exit\n");
}

float Binary(float num1, char take, float num2) {
    switch (take) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0.0) {
                printf("Error: division by zero\n");
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
            printf("Invalid binary operator\n");
            return 0.0;
    }
}

float Unary(char take, float num) {
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
            printf("Invalid unary operator\n");
            return 0.0;
    }
}

void Memory(float x, char slot) {
    if (slot >= 'a' && slot <= 'e') {
        memory[slot - 'a'] = x;
        printf("Value of %c is %.2f\n", slot, x);
    } else {
        printf("Invalid memory slot\n");
    }
}

float fetch(char slot) {
    if (slot >= 'a' && slot <= 'e') {
        return memory[slot - 'a'];
    }
    return 0.0;
}

// Numerical integration using the Trapezoidal Rule
float integrate(float (*func)(float), float a, float b, int n) {
    float h = (b - a) / n;
    float sum = (func(a) + func(b)) / 2.0;
    for (int i = 1; i < n; i++) {
        sum += func(a + i * h);
    }
    return sum * h;
}

// Numerical differentiation using central difference
float differentiate(float (*func)(float), float x, float h) {
    return (func(x + h) - func(x - h)) / (2 * h);
}

// Sample function to use for integration and differentiation (e.g., f(x) = x^2)
float sampleFunc(float x) {
    return x * x;
}

int main() {
    char select;
    float x, y, result;
    printf("Welcome to the calculator\n");

    do {
        choices();
        printf("Enter Your Choice: ");
        scanf(" %c", &select);

        switch (select) {
            case 'B':
                printf("Binary Operations\n");
                char op;
                printf("Enter 1st number: ");
                scanf("%f", &x);
                printf("Enter Operator (+, -, *, /, P, X, I): ");
                scanf(" %c", &op);
                printf("Enter 2nd number: ");
                scanf("%f", &y);
                result = Binary(x, op, y);
                printf("Result: %.2f\n", result);
                break;

            case 'U':
                printf("Unary Operations\n");
                printf("Enter Operator (S for sqrt, L for log, E for exp, C for ceil, F for floor): ");
                scanf(" %c", &op);
                printf("Enter a number: ");
                scanf("%f", &x);
                result = Unary(op, x);
                printf("Result: %.2f\n", result);
                break;

            case 'V':
                printf("Variable Memory\n");
                char slot;
                printf("Enter memory slot (a/b/c/d/e): ");
                scanf(" %c", &slot);
                printf("Enter a value: ");
                scanf("%f", &x);
                Memory(x, slot);
                break;

            case 'A':
                printf("Advanced Operations\n");
                printf("Binary or Unary? (B/U): ");
                char sub;
                scanf(" %c", &sub);
                if (sub == 'B') {
                    printf("Binary Operation\n");
                    char var1, var2;
                    printf("Enter first variable (a/b/c/d/e): ");
                    scanf(" %c", &var1);
                    printf("Enter Operator (+, -, *, /): ");
                    scanf(" %c", &op);
                    printf("Enter second variable (a/b/c/d/e): ");
                    scanf(" %c", &var2);
                    result = Binary(fetch(var1), op, fetch(var2));
                    printf("Result: %.2f\n", result);
                } else if (sub == 'U') {
                    printf("Unary Operation\n");
                    printf("Enter variable (a/b/c/d/e): ");
                    scanf(" %c", &slot);
                    printf("Enter Operator (S/L/E/C/F): ");
                    scanf(" %c", &op);
                    result = Unary(op, fetch(slot));
                    printf("Result: %.2f\n", result);
                } else {
                    printf("Invalid choice\n");
                }
                break;

            case 'I': {
                float a, b;
                int n;
                printf("Integration\n");
                printf("Enter lower limit a: ");
                scanf("%f", &a);
                printf("Enter upper limit b: ");
                scanf("%f", &b);
                printf("Enter number of intervals n: ");
                scanf("%d", &n);
                result = integrate(sampleFunc, a, b, n);
                printf("Integral result: %.2f\n", result);
                break;
            }

            case 'D': {
                float x, h;
                printf("Differentiation\n");
                printf("Enter point x: ");
                scanf("%f", &x);
                printf("Enter step size h (e.g., 0.001): ");
                scanf("%f", &h);
                result = differentiate(sampleFunc, x, h);
                printf("Derivative result: %.2f\n", result);
                break;
            }

            case 'E':
                printf("Exiting the calculator. Goodbye!\n");
                break;

            default:
                printf("Invalid Input\n");
                break;
        }
    } while (select != 'E');

    return 0;
}