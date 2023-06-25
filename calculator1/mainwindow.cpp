#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QStack>
#include<cmath>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    expression = "";
    result = "";
    setWindowTitle("张宇轩的计算器");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//数字1
void MainWindow::on_btn_num1_clicked()
{
    expression += "1";
    ui->show->setText(expression);

}

//数字2
void MainWindow::on_btn_num2_clicked()
{
    expression += "2";
    ui->show->setText(expression);

}

//数字3
void MainWindow::on_btn_num3_clicked()
{
    expression += "3";
    ui->show->setText(expression);

}

//数字4
void MainWindow::on_btn_num4_clicked()
{
    expression += "4";
    ui->show->setText(expression);
}

//数字5
void MainWindow::on_btn_num5_clicked()
{
    expression += "5";
    ui->show->setText(expression);

}

//数字6
void MainWindow::on_btn_num6_clicked()
{
    expression += "6";
    ui->show->setText(expression);

}

//数字7
void MainWindow::on_btn_num7_clicked()
{
    expression += "7";
    ui->show->setText(expression);

}

//数字8
void MainWindow::on_btn_num8_clicked()
{
    expression += "8";
    ui->show->setText(expression);

}

//数字9
void MainWindow::on_btn_num9_clicked()
{
    expression += "9";
    ui->show->setText(expression);

}

//数字0
void MainWindow::on_btn_num0_clicked()
{
    expression += "0";
    ui->show->setText(expression);

}

//左括号（
void MainWindow::on_btn_numsign1_clicked()
{
    expression += "(";
    ui->show->setText(expression);

}

//右括号）
void MainWindow::on_btn_numsign2_clicked()
{
    expression += ")";
    ui->show->setText(expression);

}

//且||
void MainWindow::on_btn_sign5_clicked()
{
    expression += "&&";
    ui->show->setText(expression);

}

//或&&
void MainWindow::on_btn_sign6_clicked()
{
    expression += "||";
    ui->show->setText(expression);

}

//小数点.
void MainWindow::on_btn_sign7_clicked()
{
    expression += ".";
    ui->show->setText(expression);

}

//除号 ÷
void MainWindow::on_btn_sign8_clicked()
{
    expression += "/";
    ui->show->setText(expression);

}

//乘号 ×
void MainWindow::on_btn_sign9_clicked()
{
    expression += "*";
    ui->show->setText(expression);
}

//减号－
void MainWindow::on_btn_sign10_clicked()
{
    expression += "-";
    ui->show->setText(expression);
}

//加号＋
void MainWindow::on_btn_sign11_clicked()
{
    expression += "+";
    ui->show->setText(expression);
}

//进行运算符优先级比较
int compare(char c)
{
    switch (c)
    {
    case '#': return 0;
    case '+': return 2;
    case '-': return 2;
    case '*': return 3;
    case '/': return 3;
    case '(': return 6;
    case ')': return 1;
    case '&': return 4;
    case '|': return 4;
    case '!': return 5;
    default: break;
    }
    return 0;
}

//四则运算
double calculate(char c = '#', double num1 = 1, double num2 = 1)
{
    switch (c)
    {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*':
              return num1 * num2;
    case '/': if(num2==0)    //对于分母是0的容错处理,如果分母是0返回一个特殊值
              return 9999;
              return num1 / num2;
    case '&': if (num2 != 0 && num1 != 0)  return 1;
            else          return 0;
    case '|': if (num2 == 0 && num1 == 0) return 0;
            else           return 1;
    default: break;
    }
    return 0;
}

//判断非！
double judge(double a)
{
    if (a == 0)  return 1;
    else      return 0;
}

//等于号＝
void MainWindow::on_btn_sign12_clicked()
{
    if (ui != nullptr)
    {
        QStack<double> str1;  // 数字栈
        QStack<char> str2;    // 运算符栈
        expression += '#';    // 在表达式末尾添加 '#' 标识结束
        char* a = expression.toLocal8Bit().data();  // 将字符串转换为 char 数组
        str2.push('#');       // 将 '#' 入栈作为初始标识符
        int length = strlen(a);

        for (int i = 0; i < length; i++)
        {
            if (a[i] <= 47 || a[i] == 124)  // 当 a[i] 是运算符时
            {
                if (a[i] == '#' && str2.top() == '#')  // 两个 '#' 碰到一起表示运算结束
                    break;
                if (str2.top() == '(')  // 对括号特殊处理
                {
                    if (a[i] == ')')
                    {
                        str2.pop();   // 弹出 '('
                        continue;
                    }
                    str2.push(a[i]);  // 将 '(' 入栈
                    continue;
                }
                else if (a[i] == '&')  // 对逻辑与运算符特殊处理
                {
                    if (a[i + 1] == '&')
                    {
                        i++;   // 跳过第二个 '&'
                    }
                }
                else if (a[i] == '|')  // 对逻辑或运算符特殊处理
                {
                    if (a[i + 1] == '|')
                    {
                        i++;   // 跳过第二个 '|'
                    }
                }
                if (compare(str2.top()) >= compare(a[i]))  // 判断运算符优先级
                {
                    if (str2.top() == '!')  // 对取反运算符特殊处理
                    {
                        double vel = judge(str1.top());  // 取出栈顶元素进行运算
                        str1.pop();
                        str2.pop();
                        str1.push(vel);  // 将结果入栈
                        i--;  // 要把 a[i] 再走一遍，否则同级运算 a[i] 不能入栈
                    }
                    else
                    {
                        char temp1 = str2.top();
                        str2.pop();
                        double temp2 = str1.top();
                        str1.pop();
                        double temp3 = str1.top();
                        str1.pop();
                        str1.push(calculate(temp1, temp3, temp2));  // 进行运算并将结果入栈
                        i--;  // 要把 a[i] 再走一遍，否则同级运算 a[i] 不能入栈
                        continue;
                    }
                }
                else
                {
                    str2.push(a[i]);  // 运算符优先级较低，入栈
                    continue;
                }
            }
            else  // 对数字的处理
            {
                double sum = (a[i]) - 48;
                for (; a[i + 1] > 47 && a[i + 1] != 124; i++)  // 实现多位数的运算
                    sum = sum * 10 + (a[i + 1]) - 48;
                if (a[i + 1] == 46)    //判断小数点
                {
                    int j = 1;
                    i = i + 2;
                    for (; a[i] > 47 && a[i] != 124; i++)
                    {
                        sum = sum + pow(10, -j) * ((a[i]) - 48); //计算小数部分
                        j++;
                    }
                    i--;
                }
                str1.push(sum); //将数字入栈
            }
        }
        double num = str1.top(); //获取最终结果
        if(num==9999)
        {
            ui->res->setText("error");
        }
        else
        {
            result = QString::number(num);// 将结果转换为字符串

            ui->res->setText(result);// 在界面上显示结果
        }
    }
}

//Delet键 后退一个数据
void MainWindow::on_btn_sign4_clicked()
{
    expression = expression.left(expression.length() - 1);
    ui->show->setText(expression);
}

//C键 全部清零
void MainWindow::on_btn_sign3_clicked()
{
    expression = "";
    result = "0";
    ui->show->setText(expression);
    ui->res->setText(result);
}

//CE键盘 只清空当前输入的数据
void MainWindow::on_btn_sign2_clicked()
{
    expression = "";
    ui->show->setText(expression);
}

//非！
void MainWindow::on_btn_sign1_clicked()
{
    expression = "!";
    ui->show->setText(expression);
}
