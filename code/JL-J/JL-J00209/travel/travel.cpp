#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;

    if(c1 == c2) cout << "1";
    else{
        cout << "0000";
        return 0;
    }

    int line1 = 0, line2 = 0;
    if(s1[0] == '1') line1 += 10;
    if(s2[0] == '1') line2 += 10;
    line1 += s1[1] - '0';
    line2 += s2[1] - '0';
    if(line1 == line2) cout << "1";
    else{
        cout << "000";
        return 0;
    }

    char ch1 = s1[2], ch2 = s2[2];
    if((ch1=='A'||ch1=='B'||ch1=='C') && (ch2=='A'||ch2=='B'||ch2=='C')) cout << "1";
    else{
        cout << "00";
        return 0;
    }

    if(abs(int(ch1 - ch2)) == 1) cout << "1";
    else cout << "0";
    return 0;

}
