#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
ll c,n,m,d,q;
ll w[N]={0};
ll a[N]={0};
ll t[N]={0};
ll k[N]={0};
ll x[N]={0};
ll y[N]={0};
bool f=0;
ll pos=0;
ll xx=0;
ll tt[N]={0};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i]>>t[i];
            xx++;
            tt[xx]=t[i];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=n;i++){
        if(k[i]>2){
            f=1;
        }
    }
    if(f==0){
        for(int i=1;i<=q;i++){
            pos+=(w[x[i]]+w[y[i]]);
            for(int j=1;j<=y[i]-1;j++){
                pos+=tt[j];
            }
            for(int j=y[i]+1;j<=2*y[i]-1;j++){
                pos+=tt[j];
            }
            cout<<pos<<endl;
            pos=0;
        }
    }else{
        for(int i=1;i<=q;i++){
            pos+=(w[x[i]]+w[y[i]]);
            for(int j=1;j<=y[i]-1;j++){
                pos+=tt[j];
            }
            for(int j=y[i]+1;j<=2*y[i]-1;j++){
                pos+=tt[j];
            }
            cout<<pos<<endl;
            pos=0;
        }
    }
    return 0;
}
