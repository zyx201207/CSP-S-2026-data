#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[35][200005];
ll fw[200005][35];
ll top[35],po[35];
bool wt[35];
ll n,m,ans;
void gt(ll x,ll i){
    ll t=x;
    ll wq=0;
    while(t){
         ll te=t%2;
         fw[i][wq]=te;
         if(te==1){
            top[wq]++;
            w[wq][top[wq]]=i;
         }
         wq++;
         t/=2;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    ll a;
    for(int i=1;i<=n;i++){
        cin>>a;
        gt(a,i);
    }
    po[0]=1;
    for(int i=1;i<=33;i++){
        po[i]=po[i-1]*2;
    }
    for(int i=31;i>=0;i--){
        ll cnt=0;
        for(int j=1;j<=top[i];j++){
            bool f=true;
            for(int k=0;k<=31;k++){
                if(wt[k]&&fw[w[i][j]][k]==0){
                    f=false;
                    break;
                }
            }
            if(f) cnt++;
        }
        if(cnt>=m){
            ans+=po[i];
            wt[i]=1;
        }
    }
    cout<<ans;
    return 0;
}
