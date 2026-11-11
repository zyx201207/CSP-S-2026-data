#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000001],g,ans,maxn;
void dfs(int x,int y,int lu){
    if(lu>maxn)return;
    if(x==y){
            if(lu==maxn)g++;
            if(lu<maxn){
                g=1;
                maxn=lu;
            }
    }
    for(int i=x+1;i<=y;i++){
        if(a[i]-a[x]<=d){
            dfs(i,y,lu+1);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int l=1;l<=n;l++){
                for(int r=l+1;r<=n;r++){
                g=0,maxn=11451400;
                dfs(l,r,0);
                if(g==2)ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
