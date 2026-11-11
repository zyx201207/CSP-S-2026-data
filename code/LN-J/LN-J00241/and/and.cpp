#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define int long long
int n,m,a[N],ma=-0x3f3f3f;
void dfs(int id,int x,int sum){
    if(x==m){
        ma=max(ma,sum);
        return;
    }
    if(id==n+1) return;
    if(x==0) dfs(id+1,x+1,a[id]);
    else dfs(id+1,x+1,sum&a[id]);
    dfs(id+1,x,sum);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0);
    cout<<ma;
    return 0;
}
