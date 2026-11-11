#include<bits/stdc++.h>
using namespace std;

long long n,m,a[200005],ans,v;
void dfs(int x,int cnt,long long sum){
    if(cnt==m) ans=max(ans,sum);
    for(int i=x+1;i<=n;i++) dfs(i,cnt+1,sum&a[i]);
    return;
}

int main(){
    freopen("and.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    v=pow(2,31)-1;
    dfs(0,0,v);
    if(n<=1) cout<<a[0];
    else cout<<ans;
    freopen("and.out","w",stdout);
    return 0;
}
