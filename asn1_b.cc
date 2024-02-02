#include <iostream>
#include <vector>
#include <iomanip>

class BigInt {
public:
    std::vector<short> d;

    BigInt(long long num = 0) {
        while (num > 0) {
            d.push_back(num % 10);
            num /= 10;
        }
        if (d.empty()) {
            d.push_back(0);
        }
    }

    BigInt operator+(const BigInt& o) const {
        BigInt res;
        res.d.clear();
        int carry = 0;
        for (size_t i = 0; i < d.size() || i < o.d.size() || carry; ++i) {
            int sum = carry;
            if (i < d.size()) sum += d[i];
            if (i < o.d.size()) sum += o.d[i];
            res.d.push_back(sum % 10);
            carry = sum / 10;
        }
        return res;
    }

    friend std::ostream& operator<<(std::ostream& out, const BigInt& num) {
        for (auto it = num.d.rbegin(); it != num.d.rend(); ++it) {
            out << *it;
        }
        return out;
    }
};

BigInt lucas(int n) {
    if (n == 0) return BigInt(2);
    if (n == 1) return BigInt(1);

    BigInt prev = 2, curr = 1; // L0 = 2, L1 = 1
    for (int i = 2; i <= n; ++i) {
        BigInt next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

int main() {
    for (int i = 0; i <= 25; ++i) {
        std::cout << "L" << i * 20 << " = " << lucas(i * 20) << std::endl;
    }
    return 0;
}
