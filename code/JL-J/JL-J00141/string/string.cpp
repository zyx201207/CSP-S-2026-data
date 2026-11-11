#include<bits/stdc++.h>
using namespace std;
#define intlong long;
string s,s2;
char a;
int n,m,x,y,t = 0,z = 0,b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> m >> a;
        for(int j = 0;j < m;j++)
            s += a;
            if(i == 6)
                break;
    }
    x = s.length() / 2;
    if(s.length() % 2 == 1)
        t = 1;
    for(int i = x - 1;i >= 0;i--)
        s2 += s[i];
    for(int i = x + t;i < s.length();i++){
        if(s[i] != s2[b])
           z++;
        b++;
    }
    cout << z;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
