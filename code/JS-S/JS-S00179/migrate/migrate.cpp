#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll flag,c,T,n,d,ans,Mn=1e9,Mt,arr[N];
void dfs(ll ed,ll pr,ll dep){
    if(pr>ed)return;
    if(pr==ed){
        if(dep<Mn)Mn=dep,Mt=1;
        else if(dep==Mn)Mt++;
    }
    for(int i=pr+1;i<=ed;i++){
        if(arr[i]-arr[pr]<=d){
            if(flag&&i+3<=ed&&arr[i+3]-arr[pr]<=d)continue;
            dfs(ed,i,dep+1);
        }
    }
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
        flag=1;
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>arr[i];
        if(c<=2)flag=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                Mn=1e9,Mt=0;
                dfs(j,i,0);
                if(Mt==2){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
