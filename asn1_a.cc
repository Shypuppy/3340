#include <iostream>

long long lucas(int n) {
    if (n == 0)
        return 2;
    if (n == 1)
        return 1;
    return lucas(n - 1) + lucas(n - 2);
}

int main() {
    for (int i = 0; i <= 10; ++i) {
        std::cout << "L" << i*5 << " = " << lucas(i*5) << std::endl;
    }
    return 0;
}