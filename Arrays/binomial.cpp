#include <bits/stdc++.h>
using namespace std;

double myPow(double x, long long n) {
    double ans = 1.0;
    long long power = n;

    if (power < 0) {   // if n is negative
        x = 1 / x;
        power = -power;
    }

    while (power > 0) {
        if (power % 2 == 1) { // if power is odd
            ans *= x;
        }
        x *= x;           // square the base
        power /= 2;       // divide exponent by 2
    }

    return ans;
}

int main() {
    cout << myPow(2, 10) << endl;   // 1024
    cout << myPow(2, -2) << endl;   // 0.25
    cout << myPow(3, 5) << endl;    // 243
}
