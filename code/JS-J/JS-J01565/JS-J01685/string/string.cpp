#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a,li=0,ans;
char s[500000100],x;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (ll i = 1; i <= n; i++){
        cin>>a>>x;
        for (ll i = 1; i <= a;i++) {
            s[++li]=x;
            //cout<<x<<'\n';
        }
    }
    for (int i = 1; i <= li/2; i++) {
        if (s[i]!=s[li-i+1]) ans++;
    }
    cout<<ans<<'\n';
    return 0;
}
