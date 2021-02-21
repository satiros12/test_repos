// Test1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

// Por puntero... Mejor, porque obliga a pasar un puntero.
int suma_p(int* a, int* b) {
    int c = *a + *b;
    *a = c;
    *b = c;
    return c;
}

// Tiene el problema de que esta memoria es de STACK y desaparece tras algun tiempo.
int* p_suma_p(int* a, int* b) {
    int c = *a + *b;
    *a = c;
    *b = c;
    return &c;
}

// Este es mejor que el anterior porque reservamos memoria en el HEAP -- Así NO se ENSUCIA la memoria anterior.
int* np_suma_p(int* a, int* b) {
    int* c = new int;
    *c = *a + *b;
    *a = *c;
    *b = *c;
    return c;
}

template <class I>
I sumag(I a, I b) {
    I result;
    result = a + b;
    return result;
}

// Por referencia -- Probalma -- El usuario no sabe a nivel de compilación que está pasando algo por referencia.
int suma_r(int& a, int& b) {
    int c = a + b;
    a = c;
    b = c;
    return c;
}

int suma(int a, int b) {
    return a + b;
}



int operacion(int a, int b, int fun(int, int)) {
    return fun(a, b);
}

// Operation overloading
int operacion(int a, int b, int* fun(int*, int*)) {
    return *fun(&a, &b); // A function with pointers
}


int main()
{
    // Hola esto es un cambio

    int a = 4;
    int b = 5;
    double ar[5];
    int* arr = new int[6];

    int* l = NULL;
    l = &a;
    int** ll = &l;
    void* lll = &ll;

    printf("-%d\n", ***(int***)lll);
    printf("+%d\n", **(int**)(*(int*)lll));
    printf("%d\n", **ll);
    printf("%d\n", *l);
    printf("%d\n", a);

    printf("--%d\n", operacion(a,b, suma));
    printf("--%d\n", operacion(a, b, np_suma_p));

    int (*fp)(int,int) = suma;

    (fp)(1,2);

    /*for (int &i : ar) {
        i = 1;
    }*/

    /*for (int j = 0; j < 5.; j++) {
        ar[j] = 1;
    }*/


    for (int j = 0; j < 5.; j++) {
        *(ar + j) = 1; // Accediendo a posiciones de memoria -- Saltos simétricos
    }

    for (double i : ar) {
        cout << i;
    }

    cout << endl;
    
    //a = 3;
    // printf("Hola que tal!!");
    if(a > 4)
        printf("%d\n", a);
    cout << a << " " << b << endl;
    { // Complex scope of operations
        int g = 5; // Solo existe entre estas llaves
        printf("%d", g);
    }
    auto c = np_suma_p(&a, &b);
    printf("%d\n", *c);
    cout << a << " " << b << " " << *c << endl;
    printf("%d\n", *c);
    printf("%d\n", sumag<int>(a,b));
    //cout << "Hello : " << a;
    //std::cout << "Hello World!\n";

    a = 0;

    cout << a << ": " << &a << endl;

    a = 6+9;

    cout << a << ": " << &a << endl;

    // Solo se puede inicializar con un array predefinidor 
    int arrn[10]; //= { 1,2,3,4,5,6,7,8,9,10 }; // Si

    // arrn = { 1,2,3,4,5,6,7,8,9,10 }; --> No

    for (int i = 0; i < 10; i++)
        cout << arrn[i] << " ";
    cout << "\n";

    for (int i = 0; i < 10; i++)
        arrn[i] = i;

     //arrn = int[]{1,2,3,4,5,6,7,8,9,10};

    for (int i = 0; i < 10; i++)
        cout << arrn[i] << " ";
    cout << "\n";

    int* parr = arrn;

    for (int i = 0; i < 10; i++)
        cout << *parr + i) << " ";
    cout << "\n";
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
