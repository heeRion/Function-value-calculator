#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 함수 프로토타입
double linear_function(double x, double m, double b); //일차함수
double quadratic_function(double x, double a, double b, double c); //이차함수
double rational_function(double x, double numerator, double denominator); //유리함수
double irrational_function(double x, char operation); //무리함수
double composite_function(double x, char operation, double operand); //합성함수
double inverse_function(double x); //역함수

// 메인 함수
int main() {
    char input[100];
    double x;
    int a;

    printf("일차함수 입력 형식 : <a>x + <b>\n");
    printf("이차함수 입력 형식 : <a>x^2 + <b>x + <c>\n");
    printf("유리함수 입력 형식 : <분자> / <분모>\n");
    printf("무리함수 입력 형식 : <연산>(x) 예)cos(3)\n");
    printf("합성함수 입력 형식 : composite(<연산>, <피연산자>)\n");
    printf("역함수 입력 형식 : inverse(x)\n");
    printf("함수 식을 입력하세요 : ");
    fgets(input, sizeof(input), stdin);

    // 입력에서 개행 문자를 제거
    input[strcspn(input, "\n")] = 0;

    printf("x에 대한 값을 입력하세요 : ");
    scanf("%lf", &x);

    // 함수를 분석 및 평가
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
            printf("잘못된 함수 표현입니다.\n");
            return 1;
        }
    }
    else if (strstr(input, "/") != NULL) {
        double numerator, denominator;
        if (sscanf(input, "%lf/%lf", &numerator, &denominator) == 2) {
            result = rational_function(x, numerator, denominator);
        }
        else {
            printf("잘못된 함수 표현입니다.\n");
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
            printf("잘못된 함수 표현입니다.\n");
            return 1;
        }
    }
    else {
        printf("잘못된 함수 표현입니다.\n");
        return 1;
    }

    // 결과를 출력합니다.
    printf("결과: %lf\n", result);

    return 0;
}

// 함수 구현
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
        printf("오류: 0으로 나눌 수 없습니다.\n");
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
        printf("잘못된 무리 함수입니다.\n");
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
        printf("잘못된 합성 함수입니다.\n");
        exit(1);
    }
}