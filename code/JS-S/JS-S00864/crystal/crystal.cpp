#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN (int)(5e5+10)
int n,m,a[MAXN],co[MAXN],ans=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++) co[i]=a[i+1]-a[i];
    co[n]=0;
    for(int i=1;i<=n;i++){
        if(i+ans>n) break;
        int j=i+1,tot=0;
        while(tot<=m&&j<=n){
            tot+=co[j]*(j-i+1),j++;
        }ans=max(ans,j-i);
    }cout<<ans<<"\n";
    return 0;
}