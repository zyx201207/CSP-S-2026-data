#include<bits/stdc++.h>
using namespace std;
short c1, l1, n1, c2, l2, n2;//l:PaiShu, n:BianHao;
string s1, s2;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    l1 = (s1[0] - '0') * 10 + (s1[1] - '0'), n1 = s1[2] - 'A';
    l2 = (s2[0] - '0') * 10 + (s2[1] - '0'), n2 = s2[2] - 'A';
    if(c1 == c2)
        if(l1 == l2)
            if(n1 <= 2 && n2 <= 2)
                printf(n1 + 1 == n2 || n1 - 1 == n2 ? "1111" : "1110");
            else if(n1 >= 3 && n2 >= 3) printf("1111");
            else printf("1100");
        else printf("1000");
    else printf("0000");
    return 0;
}