// main
#include <iostream>
#include <vector>

int main() {
    std::freopen("travel.in", "r", stdin);
    std::freopen("travel.out", "w", stdout);
    std::string s1, s2, s3, s4;
    std::cin >> s1 >> s2 >> s3 >> s4;

    if (s1 != s3) {
        std::cout << "0000";
    } else {
        if (s2[0] != s4[0] || s2[1] != s4[1]) {
            std::cout << "1000";
        } else {
            if (!( ((s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') && (s4[2] == 'A' || s4[2] == 'B' || s4[2] == 'C'))
                || (   (s2[2] == 'F' || s2[2] == 'D') && (s4[2] == 'F' || s4[2] == 'D')  ) )) {
                std::cout << "1100";
            } else {
                if (s2[2] - s4[2] == 1 || s2[2] - s4[2] == -1) {
                    std::cout << "1111";
                } else {
                    std::cout << "1110";
                }
            }
        }
    }
}
