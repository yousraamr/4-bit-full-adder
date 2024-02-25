#include <iostream>
#include <iomanip>
using namespace std;

void generateTruthTable() {
    int a[4], b[4], carryIn, carryOut, sum[4];
    cout << setw(4) << "A3" << setw(4) << "A2" << setw(4) << "A1" << setw(4) << "A0"
        << setw(4) << "B3" << setw(4) << "B2" << setw(4) << "B1" << setw(4) << "B0"
        << setw(8) << "CarryIn"
        << setw(10) << "CarryOut"
        << setw(8) << "Sum3" << setw(8) << "Sum2" << setw(8) << "Sum1" << setw(8) << "Sum0" << endl;

    for (int i = 0; i < 16; ++i) {
        a[3] = (i & 8) >> 3;
        a[2] = (i & 4) >> 2;
        a[1] = (i & 2) >> 1;
        a[0] = (i & 1);

        for (int j = 0; j < 16; ++j) {
            b[3] = (j & 8) >> 3;
            b[2] = (j & 4) >> 2;
            b[1] = (j & 2) >> 1;
            b[0] = (j & 1);

            carryIn = 0;
            carryOut = 0;
            for (int k = 0; k < 4; ++k) {
                sum[k] = a[k] ^ b[k] ^ carryIn;
                carryOut = (a[k] & b[k]) | ((a[k] ^ b[k]) & carryIn);
                carryIn = carryOut;
            }

            cout << setw(4) << a[3] << setw(4) << a[2] << setw(4) << a[1] << setw(4) << a[0]
                << setw(4) << b[3] << setw(4) << b[2] << setw(4) << b[1] << setw(4) << b[0]
                << setw(8) << carryIn
                << setw(10) << carryOut
                << setw(8) << sum[3] << setw(8) << sum[2] << setw(8) << sum[1] << setw(8) << sum[0] << endl;
        }
    }
}

int main() {
    generateTruthTable();
    
}