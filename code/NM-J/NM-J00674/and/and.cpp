#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],maxn;
void dfs(long long now,int x,int sum){
    if(sum==m){
        maxn=max(now,maxn);
        return;
    }
    for(int i=x+1;i<=n;i++){
        dfs(now&a[i],x=i,sum+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)dfs(a[i],i,1);
    cout<<maxn;
}
