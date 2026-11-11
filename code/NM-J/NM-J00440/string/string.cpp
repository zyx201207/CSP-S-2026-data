#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll t;
    cin>>t;
    vector<pair<int,char>> a(t);
    ll pos=0;
    for(ll i=0;i<t;i++){
        cin>>a[i].first>>a[i].second;
        pos++;
    }
    ll ans=0;
    ll j=pos-1;
    for(ll i=0;i<pos;){
        ll d=min(a[i].first,a[j].first);
        if(a[i].second!=a[j].second){
            ans=ans+d;
        }
        a[i].first=a[i].first-d,a[j].first=a[j].first-d;
        if(a[j].first==0){
            j--;
        }
        if(a[i].first==0){
            i++;
        }
        if(j<=i||j>=pos||i<0||j<=0||i>=pos){
            cout<<ans;
            return 0;
        }
    }
    return 0;
}
