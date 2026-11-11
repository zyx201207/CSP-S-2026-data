#include <iostream>
#include <vector>

std::string c1, s1, c2, s2;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    std::cin >> c1>> s1 >> c2 >> s2;
    int A=(c1==c2);
    int B=A&&(s1[0]==s2[0]&&s1[1]==s2[1]);
    int C=B&&((s1[2] <= 'C' ? s2[2] <= 'C' : s2[2] > 'C'));
    int D=C&&(std::abs(s1[2]-s2[2])==1 || (s1[2]=='D' && s2[2]=='F') || (s2[2]=='D' && s1[2]=='F'));
    std::cout << A << B << C << D;
}
