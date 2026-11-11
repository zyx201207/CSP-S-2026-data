#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,b[N],l,r;
priority_queue<ll,vector<ll>,greater<ll> >a;
bool check(ll x,ll y){
    for(ll i=x;i<=n;i++){
        if(b[i]-b[i-1]<=(b[i]-b[i-x]+y)/x){
            ll t=b[i]-b[i-x]+y-x*(b[i]-b[i-1]);
            if(x!=n||t%n==0)return true;
        }
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        ll o;
        cin>>o;
        a.push(o);
    }
    for(ll i=1;i<=n;i++){
        b[i]=b[i-1]+a.top();
        a.pop();
    }
    l=1,r=n;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid,m)==true){
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<l-1;
    return 0;
}
