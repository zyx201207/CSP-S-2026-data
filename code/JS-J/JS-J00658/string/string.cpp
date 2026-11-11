#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n,m[200010],g,ans;
char a[200010];
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m[i]>>a[i];
        for(int j=1;j<=m[i];j++){
            g++;
            s[g]=a[i];
        }
    }
    for(int i=1;i<=g/2+1;i++){
        if(s[i]!=s[g-i+1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
