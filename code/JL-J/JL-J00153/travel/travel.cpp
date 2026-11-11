#include <iostream>
#include <string>
using namespace std;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        printf("1");
        if (s1[0] == s2[0] && s1[1] == s2[1]) {
            printf("1");
            if ((s1[2] >= 65 && s1[2] <= 67 && s2[2] >= 65 && s2[2] <= 67) || (s1[2] >= 69 && s1[2] <= 70 && s2[2] >= 69 && s2[2] <= 70)) {
                printf("1");
                if ((s1[2] - s2[2] == 1) || (s1[2] - s2[2] == -1)) printf("1");
                else printf("0");
            }
            else printf("00");
        }
        else printf("000");
    }
    else printf("0000");
    fclose(stdin);
    fclose(stdout);
}
