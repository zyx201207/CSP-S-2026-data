#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],f=1,maxn=0,b[25],v[25],ans1;
void solve(){
    int x=b[1];
    for(int i=1;i<=m;i++){
        x&=b[i];
    }
    ans1=max(x,ans1);
}
void dfs(int deep){
    if(deep==m+1){
        solve();
        return;
    }
    for(int i=1;i<=n;i++){
        if(v[i]) continue;
        b[deep]=a[i];
        v[i]=1;
        dfs(deep+1);
        v[i]=0;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        if(a[i]!=a[i-1]) f=0;
    }
    if(n<=20){
        dfs(1);
        cout<<ans1;
    }
    else if(m==1) cout<<maxn;
    else if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++) ans&=a[i];
        cout<<ans;
    }
    else if(f) cout<<n-m;
    else if(m==2){
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int x=a[i]&a[j];
                if(i!=j) ans=max(ans,x);
            }
        }
        cout<<ans;

    }//no value
}
/*

*/

