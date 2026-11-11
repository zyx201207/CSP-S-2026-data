#include <bits/stdc++.h>
using namespace std;
long long n,x,ans,len;
char c;
string s = "";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(long long i = 1;i <= n;i++){
        cin >> x >> c; len += x;
        for(long long j = 1;j <= x;j++) s += c;
    }
    for(long long i = 0;i < len / 2;i++) if(s[i] != s[len-1-i]) ++ans;
    cout << ans;
    return 0;
}
