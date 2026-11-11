#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[1000010],cnt,ans,cw;
void dfs(int k,int v,int w){
    if(k>v)return;
    if(k==v){
        if(w<cw){
            cw=w;
            cnt=1;
        }
        else{
            if(w==cw){
                cnt++;
            }
        }
        return;
    }
    for(int i=k+1;i<=n;i++){
        if(a[i]-a[k]<=d){
            dfs(i,v,w+1);
        }
        else{
            break;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    for(cin>>c>>t;t--;ans=0){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                cnt=0;
                cw=LLONG_MAX;
                dfs(i,j,0);
                if(cnt==2){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
