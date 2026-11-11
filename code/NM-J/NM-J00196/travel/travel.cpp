#include<bits/stdc++.h>

using namespace std;

int p = 0;
char c1[10], s1[10], c2[10], s2[10], ans[10];

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    scanf("%s%s%s%s", c1 + 1, s1 + 1, c2 + 1, s2 + 1);
    for (int i = 1; i <= 4; i++)
        ans[i] = '0';
    if (c1[1] == c2[1] && c1[2] == c2[2]) {
        ans[1] = '1';
        if (s1[1] == s2[1] && s1[2] == s2[2]) {
            ans[2] = '1';
            if (s1[3] == 'A' || s1[3] == 'B' || s1[3] == 'C') {
                if (s2[3] == 'A' || s2[3] == 'B' || s2[3] == 'C') {
                    ans[3] = '1';
                    if (abs((s1[3] - 'a') - (s2[3] - 'a')) == 1) {
                        if (s1[3] == 'C' && s2[3] == 'D')
                            p++;
                        else
                            ans[4] = '1';
                        if (s1[3] == 'D' && s2[3] == 'C')
                            p++;
                        else
                            ans[4] = '1';
                    }
                }
            }
            if (s1[3] == 'D' || s1[3] == 'F') {
                if (s2[3] == 'D' || s2[3] == 'F') {
                    ans[3] = '1';
                   if (abs((s1[3] - 'a') - (s2[3] - 'a')) == 1) {
                        if (s1[3] == 'C' && s2[3] == 'D')
                            p++;
                        else
                            ans[4] = '1';
                        if (s1[3] == 'D' && s2[3] == 'C')
                            p++;
                        else
                            ans[4] = '1';
                   }
                }
            }

        }
    }
    printf("%s", ans + 1);
    return 0;
}
