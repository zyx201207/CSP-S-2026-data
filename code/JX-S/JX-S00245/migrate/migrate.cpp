#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,c,d[2000006],q,T,lj[2000006],ls[2000006],s;
void dfs(ll k,ll ss){
    if(ss){
        if(lj[k]>ss){
            lj[k]=ss;
            ls[k]=1;
        }else if(lj[k]==ss){
            ls[k]++;
        }
    }
    if(k==n)return;
    ll op=k;
    while(1){
        op++;
        if(d[op]-d[k]<=m&&op<=n){
            dfs(op,ss+1);
        }else{
            break;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
            s=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>d[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                lj[j]=1000000000;
                ls[j]=0;
            }
            dfs(i,0);
            for(int j=1;j<=n;j++){
                if(ls[j]==2)s++;
            }
        }
        cout<<s<<'\n';
    }
    return 0;
}
