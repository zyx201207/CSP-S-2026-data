#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N];
int main(){
//    system("diff -w crystal.out crystal4.ans");
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ll n,m;

    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    ll sum=0;
    priority_queue<ll,vector<ll>,greater<ll> > q;
    ll ans=1;
    q.push(a[1]);
    for(ll i=2;i<=n;i++){

        sum+=q.size()*1ll*(a[i]-a[i-1]);
        q.push(a[i]);
        while(sum>m){
            ll u=q.top();
            q.pop();
            sum-=a[i]-u;
        }
        ans=max(ans*1ull,1ll*q.size());
    }
    printf("%lld\n",ans);
    return 0;
}
// 14:38
