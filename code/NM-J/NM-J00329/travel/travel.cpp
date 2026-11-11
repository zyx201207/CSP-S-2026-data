// 08:52 5/5 100pts
// luogu: [px_poxiao](https://www.luogu.com.cn/user/1847473)
// qwq
// the NOI Linux has vscode with c++ extension!!! I love it!!!
#include <iostream>
#include <string>
using namespace std;
#define int long long
#define endl '\n'
int c1, c2;
string s1, s2;
int ck(char t){
    if(t == 'A' || t == 'B' || t == 'C'){
        if(t == 'B')
            return 2;
        return 1;
    }
    return 0;
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        cout << 1;
    }else{
        cout << "0000";
        return 0;
    }

    if(s1[0] == s2[0] && s1[1] == s2[1]){
        cout << 1;
    }
    else{
        cout << "000";
        return 0;
    }

    char tmp1 = s1[2], tmp2 = s2[2];
    if((ck(tmp1) > 0 && ck(tmp2) > 0) || (ck(tmp1) == 0 && ck(tmp2) == 0)){
        cout << 1;
    }
    else{
        cout << "00";
        return 0;
    }

    if((ck(tmp1) + ck(tmp2) == 3) || (ck(tmp1) + ck(tmp2) == 0))
        cout << 1;
    else
        cout << 0;
}
// never gonna give you up
/*
//freopen("travel.in", "r", stdin);
// freopen("travel.in", "r", stdin);
freopen("travel1.in", "r", stdin);
freopen("travel.in", "w", stdin);
freopen("travel.in", "r", stdout);
freopen("travel.in", "w", stdout);

//freopen("travel.out", "w", stdout);
// freopen("travel.out", "w", stdout);
freopen("travel1.out", "r", stdin);
freopen("travel.out", "w", stdin);
freopen("travel.out", "r", stdout);
freopen("travel.out", "w", stdout);
freopen("travel.ans", "w", stdout);
*/