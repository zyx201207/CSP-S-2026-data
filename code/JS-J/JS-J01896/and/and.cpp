#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
long long ans=LONG_LONG_MIN;
void dfs(long long sum,int x,int i){
    if(x==m){
        ans=max(ans,sum);
        return ;
    }
    if(i>n) return;
    dfs(sum==0?a[i]:sum&a[i],x+1,i+1);
    dfs(sum,x,i+1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(0LL,0,1);
    cout<<ans;
    return 0;
}
