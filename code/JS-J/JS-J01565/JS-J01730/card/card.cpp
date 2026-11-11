#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+50,INF=1e18;
ll f[N],n,m;
ll ans[N];
ll nexxt[N];
map<ll,ll>mp;
bool specialA(){
    for(ll i=1;i<n;i++){
        if(f[i]>f[i+1])return 0;
    }return 1;
}
int main(){
    freopen("card.in","r",stdin);//hope: 52
    freopen("card.out","w",stdout);//n^2 log n + special A
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //i hope that I can get the 1st price
    //hope score: 352
    cin>>n>>m;
    fill(nexxt,nexxt+N,INF);
    for(ll i=1;i<=n;i++){
        cin>>f[i];
    }if(specialA()){//special task
        for(ll i=1;i<=n;i++){
            mp[f[i]]=1;
        }for(ll i=1;i<=m;i++){
            if(mp[i]){
                cout<<n<<" ";
            }else{
                cout<<"0 ";
            }
        }return 0;
    }
    for(ll i=1;i<=n;i++){
        bool flag=1;
        for(ll j=i+1;j<=n&&flag;j++){
            if(f[i]==f[j]){
                nexxt[i]=j;
                flag=0;
            }
        }
    }for(ll q=1;q<=n;q++){
        map<ll,bool>show;
        for(ll i=q;i<=n;){
            if(nexxt[i]==INF)i++;
            else i=nexxt[i];
            show[f[i]]=1;
        }for(ll i=1;i<=m;i++){
            ans[i]+=show[i];
        }
    }for(ll i=1;i<=m;i++){
        cout<<ans[i]+1<<" ";
    }
    return 0;
}
