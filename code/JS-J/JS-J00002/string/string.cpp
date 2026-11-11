#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e5+10,T=2e8;
ll s[T];
ll n,to,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        ll x;char y;
        cin>>x;cin>>y;
        for(int j=1;j<=x;j++,to++){
            s[to]=y-'a'+1;
        }
    }
    for(int i=0;i<=(to-1)/2;i++){
        if(s[i]!=s[to-i-1])ans++;
    }
    cout<<ans;
    return 0;
}
