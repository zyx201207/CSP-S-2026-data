#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m;
int a[N];
int ans=INT_MIN;
int sum;
void dfs(int dep,int cnt){
    if(dep==1) sum=a[dep];
    if(dep==n+1){
        if(cnt>m) return;
        ans=max(ans,sum);
        return;
    }
    if(dep==1) dfs(dep+1,cnt+1);
    else{
        sum&=a[dep];
        dfs(dep+1,cnt+1);
        sum^=a[dep];
        dfs(dep+1,cnt);
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1,0);
    cout<<ans;
    return 0;
}
/*
5 3
31 3 1 15 7

*/
