#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5;
ll a[N];
unordered_multiset<ll> k[31][31];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m,op=1,cnt=0;
    cin>>n>>m;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        for(ll j=0;j<=30;j++){
            if((a[i]>>j)&1){
                k[j][cnt].insert(a[i]);
            }
        }
    }/*
    for(ll j=0;j<=30;j++){
        for(auto it:k[j][cnt]){
            cout<<it<<endl;
        }
        cout<<endl;
    }*/
    for(ll i=1;i<=30;i++){
        op*=2;
    }
    ll ans=0;
    for(ll i=30;i>=0;i--){
        if(k[i][cnt].size()>=m){
            ans+=op;
            //cout<<op<<endl;
            for(auto it:k[i][cnt]){
                for(ll j=0;j<=30;j++){
                    if((it>>j)&1){
                        k[j][cnt+1].insert(it);
                    }
                }
            }
            cnt++;
        }
        op/=2;
    }
    cout<<ans<<endl;
    return 0;
}
/*
4
2
3 15 12 12
*/
/*
5 3
31 3 1 15 7
*/
