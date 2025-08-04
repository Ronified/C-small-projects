#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double memory = 0;
int angle_mode = 0; // 0 = degrees, 1 = radians

double toRadians(double x) {
    return angle_mode ? x : x * (M_PI / 180.0);
}

double factorial(int n) {
    if (n < 0) return -1;
    double result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

void printMenu() {
    printf("\n====== CASIO-LIKE SCIENTIFIC CALCULATOR ======\n");
    printf("Select an operation:\n");
    printf(" 1. Addition (+)\n");
    printf(" 2. Subtraction (-)\n");
    printf(" 3. Multiplication (*)\n");
    printf(" 4. Division (/)\n");
    printf(" 5. Power (x^y)\n");
    printf(" 6. Square Root (√x)\n");
    printf(" 7. Sine (sin x)\n");
    printf(" 8. Cosine (cos x)\n");
    printf(" 9. Tangent (tan x)\n");
    printf("10. Natural Log (ln x)\n");
    printf("11. Log base 10 (log x)\n");
    printf("12. Factorial (n!)\n");
    printf("13. Toggle Angle Mode (Current: %s)\n", angle_mode ? "Radians" : "Degrees");
    printf("14. Memory Add (M+)\n");
    printf("15. Memory Subtract (M-)\n");
    printf("16. Memory Recall (MR)\n");
    printf("17. Memory Clear (MC)\n");
    printf(" 0. Exit\n");
    printf("==============================================\n");
}

int main() {
    int choice;
    double a, b;

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &a, &b);
                printf("Result: %.8lf\n", a + b);
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &a, &b);
                printf("Result: %.8lf\n", a - b);
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &a, &b);
                printf("Result: %.8lf\n", a * b);
                break;
            case 4:
                printf("Enter dividend and divisor: ");
                scanf("%lf %lf", &a, &b);
                if (b != 0)
                    printf("Result: %.8lf\n", a / b);
                else
                    printf("Error: Division by zero\n");
                break;
            case 5:
                printf("Enter base and exponent: ");
                scanf("%lf %lf", &a, &b);
                printf("Result: %.8lf\n", pow(a, b));
                break;
            case 6:
                printf("Enter number: ");
                scanf("%lf", &a);
                if (a >= 0)
                    printf("Result: %.8lf\n", sqrt(a));
                else
                    printf("Error: Square root of negative number\n");
                break;
            case 7:
                printf("Enter angle: ");
                scanf("%lf", &a);
                printf("Result: %.8lf\n", sin(toRadians(a)));
                break;
            case 8:
                printf("Enter angle: ");
                scanf("%lf", &a);
                printf("Result: %.8lf\n", cos(toRadians(a)));
                break;
            case 9:
                printf("Enter angle: ");
                scanf("%lf", &a);
                printf("Result: %.8lf\n", tan(toRadians(a)));
                break;
            case 10:
                printf("Enter number: ");
                scanf("%lf", &a);
                if (a > 0)
                    printf("Result: %.8lf\n", log(a));
                else
                    printf("Error: ln undefined for non-positive values\n");
                break;
            case 11:
                printf("Enter number: ");
                scanf("%lf", &a);
                if (a > 0)
                    printf("Result: %.8lf\n", log10(a));
                else
                    printf("Error: log undefined for non-positive values\n");
                break;
            case 12:
                printf("Enter a non-negative integer: ");
                scanf("%lf", &a);
                if (a == (int)a && a >= 0)
                    printf("Result: %.0lf\n", factorial((int)a));
                else
                    printf("Error: Enter a valid non-negative integer\n");
                break;
            case 13:
                angle_mode = !angle_mode;
                printf("Switched to %s mode\n", angle_mode ? "Radians" : "Degrees");
                break;
            case 14:
                printf("Enter number to add to memory: ");
                scanf("%lf", &a);
                memory += a;
                printf("Memory updated to: %.2lf\n", memory);
                break;
            case 15:
                printf("Enter number to subtract from memory: ");
                scanf("%lf", &a);
                memory -= a;
                printf("Memory updated to: %.2lf\n", memory);
                break;
            case 16:
                printf("Memory Recall: %.2lf\n", memory);
                break;
            case 17:
                memory = 0;
                printf("Memory cleared.\n");
                break;
            case 0:
                printf("Exiting calculator. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again!\n");
        }

    } while (choice != 0);

    return 0;
}

