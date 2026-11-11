#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[2000005];
ll ds[100005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    ll cnt=0;
    while(t--){
        int n;
        ll d;
        ll ms=0;
        cin>>n>>d;
        ll o=n;

        for(ll i=1;i<=n;i++){
            cin>>x[i];
            if(x[i]-x[i-1]>d){
                o=min(o,i-1);
            }
        }
        ll ds[o];

        for(ll i=1;i<=o;i++){
        for(ll j=i+1;j<=o;j++){

            int d1=x[j]-x[i];
            int cur=x[i];
            for(int k=j;k>=i+1;k--){
                if(x[k]-cur<=d){
                    d1-=(x[k]-cur);
                    ms++;
                    cur=x[k];
                }

               if(d1==0) break;
             }
            ds[i]=ms;
            ms=0;
            sort(ds,ds+n);
            if((ds[1]==ds[2])&&(ds[2]!=ds[3])) cnt++;
        }
    }
    cout<<cnt;

    }
return 0;
}

