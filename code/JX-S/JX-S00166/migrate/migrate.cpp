#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod=998244353;
const int N=2000020;
int c,n,m,cnt,ans,ta;
int a[N];
int flg;
void dfs(int s,int t,int res){
    if(s>=t){
        if(ans==1e9){
            ans=res;
            cnt=1;
            flg=1;
        }else if(res==ans){
            cnt++;
        }
        return;
    }
    if(res>=ans||cnt>2)return;
    for(int i=s+1;i<=n;i++){
        if(a[i]-a[s]>m||i>t){
            for(int j=i-1;j>=s+1;j--){
                flg=0;
                dfs(j,t,res+1);
                if(flg==0)return;
            }
            return;
        }
    }
    for(int j=n;j>=s+1;j--){
                flg=0;
                dfs(j,t,res+1);
                if(flg==0)return;
            }
            return;
    /*
    priority_queue<node>q;
    q.push((node){s,0});
    while(!q.empty()){
        node px=q.top();
        for(int i=px.x+1;i<=n;i++){
            if(a[i]-a[px.x]<=m){
                q.push()
            }
        }
    }
    */
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ta=0;
    for(int i=1;i<n;i++){
        for(int j=i+3;j<=n;j++){
            ans=1e9,cnt=0;
            dfs(i,j,0);
            if(cnt==2){
                ta++;
            }
        }
    }
    cout<<ta<<endl;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _=1;
    cin>>c>>_;
    while(_--){
        solve();
    }
}
