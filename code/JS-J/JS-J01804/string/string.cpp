#include <bits/stdc++.h>
using namespace std;
int n;
string s="", s1="";
long long cnt, x;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin >> a >> c;
        for(int j=1;j<=a;j++){
            s += c;
        }
    }
    x = s.size()-1;
    for(int i=x;i>=0;i--){
        s1 += s[i];
    }
    for(int i=0;i<=x;i++){
        if(s[i] != s1[i]){
            s1[i] = s[i];
            s[x-i] = s1[i];
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}
