#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n,m,a[200001],r,maxa=-1,inin=1,netup,qwq;
void dfs(int x,int q){
    if(x==0){
        maxa=max(maxa,inin);
        return;
    }
    for(int i=netup+1;i<=n;i++){
        qwq=inin;
        inin&=i;
        netup=i;
        dfs(x-1,netup);
        inin=qwq;

    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,greater<int>());
    if(m==1){
        cout<<a[1]<<'\n';
        return 0;
    }
    if(m==n){
        for(int i=1;i<=n;i++) r&=a[i];
        cout<<r<<'\n';
        return 0;
    }
    dfs(m,1);

    cout<<maxa<<'\n';
    return 0; 
}