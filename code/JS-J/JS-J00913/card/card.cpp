#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],b[N],sflag;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(a[i-1]>a[i]){
            sflag=1;
        }
    }
    if(sflag==0){
        for(ll i=1;i<=n;i++){
            b[a[i]]=i;
        }
        for(ll i=1;i<=m;i++){
            cout<<b[i]<<' ';
        }
        return 0;
    }

    for(ll i=1;i<=n;i++){
        vector<ll> t;
        t.clear();
        for(ll j=i;j<=n;j++){
            ll flag=0;
            for(ll e=0;e<ll(t.size());e++){
                if(t[e]==a[j]){
                    for(ll d=e;d<ll(t.size());){
                        t.erase(t.begin()+d);
                    }
                    flag=1;
                    break;
                }
            }
            t.push_back(a[j]);
        }
        for(ll j=0;j<ll(t.size());j++){
            b[t[j]]++;
        }

    }
    for(ll i=1;i<=m;i++){
            cout<<b[i]<<' ';
    }
    return 0;
}
