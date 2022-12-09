


#include<iostream>
#include<locale.h>
#include<map>
#include<vector>
#include<string>
#include<stack>
using namespace std;
class ArithmeticExpression
{
    string infix;
    string postfix;
    map<char, int>priority{ make_pair('(',0), make_pair('+',1), make_pair('-',1), make_pair('*',2), make_pair('/',2) };

    string toPostfix()//преобразование в обратную польскую запись
    {
        int f = 0;
        postfix = "";
        stack<char> Stack;
        char num;
        for (int pos = 0; pos < infix.length(); pos++)
        {
            num = infix[pos];
            if (isdigit(num))
            {
                postfix += GetStringNumber(infix, &pos);
                postfix += ' ';
            }
            else if (num == '(')
            {
                f += 1;
                Stack.push(num);
            }   
            else if (num == ')')
            {
                while (!Stack.empty() > 0 && Stack.top() != '(')
                {
                    postfix += Stack.top();
                    Stack.pop();
                }
                Stack.pop();
                f -= 1;
            }
            else if (priority.find(num) != priority.end())
            {
                char op = num;
                while (!Stack.empty() > 0 && priority[Stack.top()] >= priority[op])
                {
                    postfix += Stack.top();
                    Stack.pop();
                }
                Stack.push(op);
            }
            /*if (f != 0)
                throw invalid_argument("invalid_input");*/

        }
        while (!Stack.empty())
        {
            postfix += Stack.top();
            Stack.pop();
        }
        if (f != 0)
            throw invalid_argument("invalid_input");
        return postfix;
    }
    double GetNumber(string expr, int* i)//преобразование строки в число, начиная с номера pos
    {
        string num = "";
        for (int j = *i; j < expr.length(); j++, (*i)++)
            if (isdigit(expr[j]))
                num += expr[j];
            else
                break;
        (*i)--;
        return stoi(num);

    }
    string GetStringNumber(string expr, int* i)
    {
        string num = "";
        for (int j = *i; j < expr.length(); j++, (*i)++)
            if (isdigit(expr[j]))
                num += expr[j];
            else
                break;
        (*i)--;
        return num;
    }
    double math(double s1, double s2, char op)
    {
        switch (op)
        {
        case '+': return s1 + s2;
        case '-': return s1 - s2;
        case '*': return s1 * s2;
        case '/': return s1 / s2;
        }
    }
public:
    void  parse(string s)
    {
        infix = s;
    }
    void convert()
    {
        toPostfix();
    }
    ArithmeticExpression(string _infix="") :infix(_infix)
    {
        toPostfix();
    }
    string GetInfix() const
    {
        return infix;
    }
    string GetPostfix() const
    {
        return postfix;
    }

    double calc()
    {
        double last;
        double first;
        stack<double> operands;
        char c;
        for (int i = 0; i < postfix.length(); i++)
        {
            c = postfix[i];
            if (isdigit(c))
                operands.push(GetNumber(postfix, &i));
            else if (priority.find(c) != priority.end())
            {
                last = operands.top();
                operands.pop();
                first = operands.top();
                operands.pop();
                operands.push(math(first, last, c));
            }

        }
        double x = operands.top();
        operands.pop();

        return x;

    }

};

//int main()
//{
//    setlocale(2, "rus");
//    string expression;
//    cout << "введите выражение" << endl;
//    cin >> expression;
//    ArithmeticExpression EXPR(expression);
//    cout << "результат выражения:" << endl;
//    cout << EXPR.calc() << endl;
//    while (true)
//    {
//        cout << "для прекращения вычисления введите stop" << endl;
//        cin >> expression;
//        if (expression == "stop")
//            break;
//        else
//        {
//            EXPR.parse(expression);
//            EXPR.convert();
//            cout << "результат выражения:" << endl;
//            cout << EXPR.calc() << endl;
//        }
//    }
//    return 0;
//}

