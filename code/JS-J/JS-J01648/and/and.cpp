#include <bits/stdc++.h>
using namespace std;
int n,m,a[200015];
int daan=-1,res=0;
void dfs(int u,int last){
    if(u==m+1){
        cout<<res<<endl;
        daan=max(daan,res);
        return;
    }
    int yres=res;
    for(int i=last+1;i<=n;i++){
        if(yres==0){
            res=a[i];
        }
        else res=res&a[i];

        dfs(u+1,i);
        res=yres;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int h=1,maxx=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        h=(i==1?a[i]:h&a[i]);
        maxx=max(maxx,a[i]);
    }
    sort(a+1,a+n+1);
    if(m==n)cout<<h;
    else if(m==1)cout<<maxx;
    else if(m==n-1){
        int ans=-1;
        for(int i=1;i<=n;i++){
            ans=max(ans,h&a[i]);
        }
        cout<<ans;
    }
    else if(n<=2000){
        dfs(1,0);
        cout<<daan;
    }
    else{
        int k=1;
        for(int i=n;i>=n-m-1;i--)k=k&a[i];
        cout<<k;
    }
    return 0;
}
