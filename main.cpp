#include "Datum.h"
#include <iostream>

using namespace std;

int main()
{
    Datum d1;
    Datum d2(2022, 3, 17);
    Datum d3;
    d3 = d2;

    cout << "A 'maig()' fuggveny nem hasznalhato!\n\n";

    cout << "Konstruktorok: \n";
    cout << d1 << d2 << d3 << endl;

    Datum d4;
    cout << "Bekeres demonstralasa: \n";
    cout << "Adj meg egy datumot: "; cin >> d4;
    cout << "A megadott datum: " << d4 << endl;

    cout << "Szokoev: \n";
    if(d4.szokoev())
        cout << "Ez az ev szokoev! \n\n";
    else
        cout << "Ez az ev nem szokoev! \n\n";

    cout << "Honap: \n";
    cout << d4.honap() << endl << endl;

    Datum d5(2020, 2, 28);
    Datum d6(2020, 2, 29);
    Datum d7(2021, 2, 28);
    Datum d8(2020, 12, 31);
    cout << "Inkrementalas: \n";
    cout << "A jelenlegi datumok: \n" << d5 << d6 << d7 << d8 << endl;
    d5++; d6++; d7++; d8++;
    cout << "Inkrementalas utan: \n" << d5 << d6 << d7 << d8 << endl;

    Datum d9(2020, 3, 1);
    Datum d10(2021, 3, 1);
    Datum d11(2022, 1, 1);
    cout << "Dekrementalas: \n";
    cout << "A jelenlegi datumok: \n" << d9 << d10 << d11 << endl;
    d9--; d10--; d11--;
    cout << "Dekrementalas utan: \n" << d9 << d10 << d11 << endl;


    cout << "Operatorok: \n";
    cout << "A ket datum: \n" << d5 << d6;
    if(d5 == d6)
        cout << "A ket datum egyenlo! \n";
    else
        cout << "A ket datum nem egyenlo! \n";

    return 0;
}
