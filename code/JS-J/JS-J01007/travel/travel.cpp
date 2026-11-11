#include<bits/stdc++.h>
using namespace std;
string s,ss,c,cc;
int a[10] = {0,0,0,1,1,1};
int st[3][2] = {{0,1},{1,2},{3,5}};
int ffabs(int x){
    if (x < 0)
        return -x;
    return x;
}
int check(int x,int y){
    if (x > y)
        swap(x,y);
    for (int i = 0;i < 3;i++){
        if (st[i][0] == x && st[i][1] == y)
            return 1;
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> c >> ss >> cc;
    if (s != ss){
        cout << "0000";
        return 0;
    }
    cout << 1;
    if (c[0] != cc[0] || c[1] != cc[1]){
        cout << "000";
        return 0;
    }
    cout << 1;
    if (a[c[2]-'A'] != a[cc[2]-'A']){
        cout << "00";
        return 0;
    }
    cout << 1;
    if (check(c[2]-'A',cc[2]-'A'))
        cout << 1;
    else cout << 0;
    return 0;
}
