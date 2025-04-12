#include "solver.h"
#include "Functions.h"
#include <iostream>
#include <iomanip>
/*
Справка:

Solver Sol(num_intervals, TEST); - создаём решение (число интервалов сетки, тип задачи)
    Типы задач:
    TEST - тестовая
    MAIN1 - 1 вариант (варианты в пдфке на гугл диске капкаева)
    MAIN2 - 2 вариант
    MAIN3 - 3 вариант
    MAIN4 - 4 вариант
    OSC - осциллирующая 

Какие геттеры нужны для построения
    1 таблицы итерируемся по num_nodes так как это сетка сплайна:
    getA()
    getB()
    getC()
    getD() - это всё для построения коэффициентов (возвращают вектор)
    getX_for_coef_table() - возвращаются узлы (вектор)
    get_n_step() - возвращает шаг, с которым идём по соновной сетке(хз , может и не нужен)

    2 и 3 таблицы : (итерируемся по num_nodes*2 так как это контрольная сетка)
    getX() - возвращаются узлы (вектор)
    getF()
    getDF()
    getD2F()
    getS()
    getDS()
    getD2S() - это всё векторы основной функции и функции сплайна F - основная S - сплайна,
               D и D2 - их производные
    get_N_step() - возвращает шаг, с которым идём по соновной сетке(хз , может и не нужен)

    Справки:
    getF_ERRROR();
    getF_ERRROR_X();
    getDF_ERRROR();
    getDF_ERRROR_X();
    getD2F_ERRROR();
    getD2F_ERRROR_X(); - все возвращают максимальную погрешность и соответсвующий ей x;

*/

int main() {
   
    int num_intervals{ 5 };
    Solver Sol(num_intervals, Main3, NOT_EGU);
    Sol.Solve();
    
    auto f = Sol.getF();
    auto df = Sol.getDF();
    auto d2f = Sol.getD2F();
    auto s = Sol.getS();
    auto ds = Sol.getDS();
    auto d2s = Sol.getD2S();
    //сюда пишется код красивый для вывода таблиц

    
    for (int i = 0; i < s.size(); ++i) {
        if (i != s.size() - 1) {
            std::cout << std::setprecision(8) << s[i] << std::setw(15);
        }
        else {
            std::cout << std::setprecision(8) << s[i];
        }
    }
    std::cout << std::endl;

    for (int i = 0; i<ds.size(); ++i) {
        if (i != ds.size() - 1) {
            std::cout << std::setprecision(7)  << ds[i] << std::setw(15);
        }
        else {
            std::cout << std::setprecision(7) << ds[i];
        }
    }
    std::cout << std::endl;

    for (int i = 0; i < d2s.size(); ++i) {
        if (i != d2s.size() - 1) {
            std::cout << std::setprecision(6) << d2s[i] << std::setw(15);
        }
        else {
            std::cout << std::setprecision(6) << d2s[i];
        }
    }
    std::cout << std::endl;


    std::cout<<std::endl;

    for (int i = 0; i < f.size(); ++i) {
        if (i != f.size() - 1) {
            std::cout << std::setprecision(8) << f[i] << std::setw(15);
        }
        else {
            std::cout << std::setprecision(8) << f[i];
        }
    }
    std::cout << std::endl;

    for (int i = 0; i < df.size(); ++i) {
        if (i != df.size() - 1) {
            std::cout << std::setprecision(7) << df[i] << std::setw(15);
        }
        else {
            std::cout << std::setprecision(7) << df[i];
        }
    }
    std::cout << std::endl;

    for (int i = 0; i < d2f.size(); ++i) {
        if (i != d2f.size() - 1) {
            std::cout << std::setprecision(6) << d2f[i] << std::setw(15);
        }
        else {
            std::cout << std::setprecision(6) << d2f[i];
        }
    }
    std::cout << std::endl;

    return 0;
}