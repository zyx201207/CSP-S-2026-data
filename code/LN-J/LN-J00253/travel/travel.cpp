#include <bits/stdc++.h>
using namespace std;
string l1,l2;
char d1,d2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s1,s2;
    string c1,c2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1==c2) cout << 1;
    else cout << 0;
    l1 = l1 + s1[0]+s1[1];
    l2 = l2 + s2[0]+s2[1];
    //cout << endl << l1 << " " << l2 << endl;
    d1 = s1[2];
    d2 = s2[2];
    if (c1==c2&&l1==l2) cout << 1;
    else cout << 0;
    if (c1==c2&&l1==l2&&((d1<='C'&& d2<='C')||(d1>='D'&&d2>='D'))) cout << 1;
    else cout << 0;
    if (c1==c2&&l1==l2&&(abs((int)(d1-d2))==1&&(d1!='C'&&d2!='D')&&(d1!='D'&&d2!='C'))) cout << 1;
    else  cout << 0;
    return 0;
}


