#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N=2e6+5;
ll c,t;
ll n,d;
ll x[N];
ll ans=0x3f3f3f3f3f3f3f3f,numb=0;
void dfs(int pos,int zd,int num){
    if(pos==zd){
        // cout<<pos<<" "<<zd<<" "<<num<<'\n';
        if(ans>num){
            ans=num;
            numb=1;
        }else if(ans==num){
            numb++;
        }
        return ;
    }
    for(int i=pos+1;i<=zd;i++){
        if(x[i]-x[pos]>d)break;
        dfs(i,zd,num+1);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        ll answ=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                numb=0;ans=0x3f3f3f3f;
                // if(i==j)continue;
                if(x[j]-x[i]<=d)continue;
                dfs(i,j,0);
                if(numb==2){
                    answ++;
                }
                // cout<<numb<<" ";
            }
        }
        cout<<answ<<'\n';
    }
    return 0;
}