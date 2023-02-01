#include<iostream>

using namespace std;

float sum(float, float);
float subtract(float, float);
float product(float, float);
float divide(float, float);


int main()
{
    float num1, num2, result;
    char operation;

    cout << "Enter A : ";
    cin >> num1;
    cout << "Enter B : ";
    cin >> num2;
    cout << "What function do you want to perform? (+,-,*,/) : ";
    cin >> operation;

    if(operation == '+')
    {
        result = sum(num1, num2);
        cout << "A + B = " << num1 << " + " << num2 << " = " << result << endl;
    }

    else if(operation == '-')
    {
        result = subtract(num1, num2);
        cout << "A - B = " << num1 << " - " << num2 << " = " << result << endl;
    }

    else if(operation == '*')
    {
        result = product(num1, num2);
        cout << "A * B = " << num1 << " * " << num2 << " = " << result << endl;
    }

    else if(operation == '/')
    {
        result = divide(num1, num2);
        cout << "A / B = " << num1 << " / " << num2 << " = " << result << endl;
    }

    else
    {
        cout << "Invalid Input!";
    }
}


float sum(float a, float b)
{
    float sum;

    sum = a  + b;

    return(sum);
}

float subtract(float a, float b)
{
    float subtract;

    subtract = a - b;

    return(subtract);
}

float product(float a, float b)
{
    float product;

    product = a * b;

    return(product);
}

float divide(float a, float b)
{
    float divide;

    divide = a / b;

    return(divide);
}
