#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// �Լ� ������Ÿ��
double linear_function(double x, double m, double b); //�����Լ�
double quadratic_function(double x, double a, double b, double c); //�����Լ�
double rational_function(double x, double numerator, double denominator); //�����Լ�
double irrational_function(double x, char operation); //�����Լ�
double composite_function(double x, char operation, double operand); //�ռ��Լ�
double inverse_function(double x); //���Լ�

// ���� �Լ�
int main() {
    char input[100];
    double x;
    int a;

    printf("�����Լ� �Է� ���� : <a>x + <b>\n");
    printf("�����Լ� �Է� ���� : <a>x^2 + <b>x + <c>\n");
    printf("�����Լ� �Է� ���� : <����> / <�и�>\n");
    printf("�����Լ� �Է� ���� : <����>(x) ��)cos(3)\n");
    printf("�ռ��Լ� �Է� ���� : composite(<����>, <�ǿ�����>)\n");
    printf("���Լ� �Է� ���� : inverse(x)\n");
    printf("�Լ� ���� �Է��ϼ��� : ");
    fgets(input, sizeof(input), stdin);

    // �Է¿��� ���� ���ڸ� ����
    input[strcspn(input, "\n")] = 0;

    printf("x�� ���� ���� �Է��ϼ��� : ");
    scanf("%lf", &x);

    // �Լ��� �м� �� ��
    double result;

    if (strstr(input, "x") != NULL) {
        double a, b, c;
        if (sscanf(input, "%lfx + %lf", &a, &b) == 2) {
            result = linear_function(x, a, b);
        }
        else if (sscanf(input, "%lfx^2 + %lfx + %lf", &a, &b, &c) == 3) {
            result = quadratic_function(x, a, b, c);
        }
        else {
            printf("�߸��� �Լ� ǥ���Դϴ�.\n");
            return 1;
        }
    }
    else if (strstr(input, "/") != NULL) {
        double numerator, denominator;
        if (sscanf(input, "%lf/%lf", &numerator, &denominator) == 2) {
            result = rational_function(x, numerator, denominator);
        }
        else {
            printf("�߸��� �Լ� ǥ���Դϴ�.\n");
            return 1;
        }
    }
    else if (strstr(input, "sqrt") != NULL || strstr(input, "cos") != NULL || strstr(input, "inverse") != NULL) {
        result = irrational_function(x, input[0]);
    }
    else if (strstr(input, "composite") != NULL) {
        char operation;
        double operand;
        if (sscanf(input, "composite(%c,%lf)", &operation, &operand) == 2) {
            result = composite_function(x, operation, operand);
        }
        else {
            printf("�߸��� �Լ� ǥ���Դϴ�.\n");
            return 1;
        }
    }
    else {
        printf("�߸��� �Լ� ǥ���Դϴ�.\n");
        return 1;
    }

    // ����� ����մϴ�.
    printf("���: %lf\n", result);

    return 0;
}

// �Լ� ����
double linear_function(double x, double m, double b) {
    return m * x + b;
}

double quadratic_function(double x, double a, double b, double c) {
    return a * x * x + b * x + c;
}

double rational_function(double x, double numerator, double denominator) {
    if (denominator != 0) {
        return numerator / denominator;
    }
    else {
        printf("����: 0���� ���� �� �����ϴ�.\n");
        exit(1);
    }
}

double irrational_function(double x, char operation) {
    if (operation == 's') {
        return sqrt(x);
    }
    else if (operation == 'c') {
        return cos(x);
    }
    else if (operation == 'i') {
        return 1 / x;
    }
    else {
        printf("�߸��� ���� �Լ��Դϴ�.\n");
        exit(1);
    }
}

double composite_function(double x, char operation, double operand) {
    if (operation == '+') {
        return x + operand;
    }
    else if (operation == '-') {
        return x - operand;
    }
    else if (operation == '*') {
        return x * operand;
    }
    else {
        printf("�߸��� �ռ� �Լ��Դϴ�.\n");
        exit(1);
    }
}