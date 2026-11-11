#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long n,m;
long long ma=-1e9;
void dfs(long i,long long sum,long long st){
    if(i==m){
        ma=max(sum,ma);
        return;
    }
    if(st>n)return;
    dfs(i+1,sum&a[st],st+1);
    dfs(i,sum,st+1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)dfs(1,a[i],i+1);
    cout<<ma;
    return 0;
}
