#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005];
long long ans;
void dfs(long long x,int y,int z){
    if(y==0){
        ans=max(ans,x);
        return;
    }
    for(int i=z+1;i<=n-m+z+1;i++){
        long long q=x;
        if(x==0)x=a[i];
        long long p=x&a[i];
        dfs(p,y-1,i);
        x=q;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(0,m,0);
    cout<<ans<<endl;
    return 0;
}
