#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxn=-1;
void dfs(long long k,long long deth,long long now){
    if(deth==m){
        maxn=max(maxn,now);
        return ;
    }
    for(int i=k+1;i<=n;i++){
        if(deth==0)  dfs(i,deth+1,a[i]);
        else  dfs(i,deth+1,(now&a[i]));
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,0,0);
    cout<<maxn;
    return 0;
}
