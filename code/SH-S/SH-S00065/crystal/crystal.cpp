#include <bits/stdc++.h>
using namespace std;
int n;long long m;
long long a[500010],dt[500010];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    if(n==1){
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)dt[i]=dt[i-1]+a[i];
    int ans=1;
    int l=1,r=0;
    while(1){
        ++r;
        while(a[r]*(r-l+1)-(dt[r]-dt[l-1])>m)++l;
        ans=max(ans,r-l+1);
        if(r==n)break;
    }
    cout<<ans;
    return 0;
}