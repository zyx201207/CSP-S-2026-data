#include <bits/stdc++.h>
using namespace std;

int c1, c3, c2l, c4l;
char c2[110], c4[110], c21, c41;
bool ans1, ans2, ans3, ans4;

int main () {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    scanf("%d%s%d%s", &c1, c2 + 1, &c3 , c4 + 1);
    c21 = c2[3];
    c41 = c4[3];
    c2l = (c2[1] - '0') * 10 + (c2[2] - '0');
    c4l = (c4[1] - '0') * 10 + (c4[2] - '0');
    if (c1 == c3)
        ans1 = true;
    else
        ans1 = false;
    if (c2l == c4l && ans1)
        ans2 = true;
    else
        ans2 = false;
    if (ans2){
        if ((c21 <= 'C' && 'A' <= c21 && c41 <= 'C' && 'A' <= c41) || (c41 <= 'F' && 'D' <= c41 && c21 <= 'F' && 'D' <= c21))
            ans3 = true;
        else
            ans3 = false;
        if (c21 == 'A')
            if (c41 == 'B')
                ans4 = true;
            else
                ans4 = false;
        else
            if (c21 == 'B')
                if (c41 == 'A' || c41 == 'C')
                    ans4 = true;
                else
                    ans4 = false;
            else
                if (c21 == 'C')
                    if (c41 == 'B')
                        ans4 = true;
                    else
                        ans4 = false;
                else
                    if (c21 == 'D')
                        if (c41 == 'F')
                            ans4 = true;
                        else
                            ans4 = false;
                    else
                        if (c41 == 'D')
                            ans4 = true;
                        else
                            ans4 = false;
    }
    printf("%d%d%d%d", ans1, ans2, ans3, ans4);
    return 0;
}
