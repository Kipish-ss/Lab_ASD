#include <iostream>
using namespace std;
int ackermann(int, int);
int main() {
    int n, m, result;
    cout << "Enter non-negative integer n: ";
    cin >> n;
    cout << "Enter non-negative integer m: ";
    cin >> m;
    result = ackermann(n, m);
    cout << "Result = " << result;
    return 0;
}
int ackermann(int n, int m) {
    int value;
    if (n == 0) {
        value = m + 1;
    }
    else {
        if (m == 0) {
            value = ackermann(n - 1, 1);
        }
        else {
            value = ackermann(n - 1, ackermann(n, m - 1));
        }
    }
    return value;
}
