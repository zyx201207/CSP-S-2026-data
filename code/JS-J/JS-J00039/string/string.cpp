#include <bits/stdc++.h>
using namespace std;

int a,b,cnt=0;
string s,c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> a;
    for(int i=1; i<=a; i++){
        cin >> b >> c;
        for(int j=1; j<=b; j++)
            s += c;
    }
    for(int i=0; i<=s.size()/2; i++){
            if(s[i]!=s[s.size()-i-1])
            cnt++;
    }
    cout << cnt;
    return 0;
}

