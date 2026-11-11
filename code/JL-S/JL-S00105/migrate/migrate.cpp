#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,c,t,d,cnt,ans;
vector<ll> v;
void f(ll x,ll i,ll j){
    if(x>m){
        return ;
    }
    if((v[j]-v[i])<=d&&x==m){
        cnt++;
        return ;
    }
    if((v[j]-v[i])<=d&&x!=m){
        return ;
    }
    for(ll k=i+1;k<j;k++){
        if((v[i+1]-v[i])>d) return ;
        if((v[k]-v[i])<=d) f(x+1,k,j);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        v.clear();
        m=0;
        ans=0;
        cin>>n>>d;
        for(ll i=0;i<n;i++){
            ll k;
            cin>>k;
            v.push_back(k);
        }
        ll fi=v[0],idx=0;
        bool ok=true;
        while(fi<v[n-1]){
            fi+=d;
            for(ll i=n-1;i>0;i--){
                if(i<=idx){
                    ok=0;
                    break;
                }
                if(v[i]<=fi){
                    fi=v[i];
                    idx=i;
                    m++;
                    break;
                }
            }
            if(!ok) break;
        }
        m--;
        for(ll i=0;i<n;i++){
            for(ll j=i;j<n;j++){
                f(0,i,j);
                if(cnt==2) ans++;
                cnt=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
