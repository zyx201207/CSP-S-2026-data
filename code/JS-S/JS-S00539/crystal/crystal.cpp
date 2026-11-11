#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
void dfs(int step,int pre){
    int nx=pre,f=1;
    nx+=(step-1)*(a[step]-a[step-1]);
    if(a[step]==a[step-1]){
        dfs(step+1,nx);
        f=0;
    }
    if(nx>m){
        cout<<step-1;
        return;
    }
    if(f){
        dfs(step+1,nx);
    }
}
signed main(){
    freopen("crystal.in","w",stdin);
    freopen("crystal.out","r",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(1,0);
    return 0;
}
