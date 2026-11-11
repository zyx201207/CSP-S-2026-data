#include<iostream>
#include<algorithm>
using namespace std;
using ll=long long;
const int N=5e5+7;
const ll H=1e12+7;
ll a[N];
ll n,m,mx=-1;
bool check(ll x){
    ll sum=0,gs=0;
    for(int i=1;i<=n;++i)
        if(a[i]<=x) sum+=x-a[i],gs++;
    if(sum<=m){
        mx=max(mx,gs);
        return 1;
    }
    else return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    ll lo=-H,hi=H;
    while(lo<hi){
        ll mid=(lo+hi)>>1;
        if(check(mid)) lo=mid+1;
        else hi=mid;
    }
    cout<<mx<<endl;
	return 0;
}
