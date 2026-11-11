#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200005;
ll n,m;
ll a[N];
vector<ll> ls[35];
bool cmp(ll a,ll b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<35;i++){
        for(int j=1;j<=n;j++){
            if((a[j]>>i)&1) ls[i].push_back(a[j]);
        }
    }
    ll ans=0;
    for(int i=34;i>=0;i--){
        if(m<=ls[i].size()){
            ll cnt=(1LL<<35)-1;
            sort(ls[i].begin(),ls[i].end(),cmp);
            for(int j=0;j<m;j++) cnt&=ls[i][j];
            ans=cnt;
            break;
        }
    }
    cout<<ans;
    return 0;
}
