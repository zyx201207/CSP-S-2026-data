#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int maxn=5e5+5;
int n,m,a[maxn],pre[maxn];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i];
    int ans=1;
    for(int i=2;i<=n;i++){
        if(a[i]*i-pre[i]<=m){
            ans=i;
        }
    }
    cout<<ans<<'\n';
    return 0;
}