#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll m,a[500010],pre[500010];
ll cal(int l,int r){return a[r]*(r-l+1)-(pre[r]-pre[l-1]);}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    int ans=0;
    for(int i=1,j=1;i<=n;i++){
        while(cal(j,i)>m) ++j;
        ans=max(ans,i-j+1);
    }
    cout<<ans;
    return 0;
}