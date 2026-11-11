#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll n,fg;
ll m,ans=1;
ll a[N],c[N];
void check(ll x){
    ll sum=m;
    ll o=x-1;
    ll cnt=1;
    while(sum>=0&&o){
        if(sum<a[x]-a[o])    break;
        else{
            sum-=a[x]-a[o];
            cnt++;
            o--;
        }
    }
    ans=max(ans,cnt);
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i) fg++;
    }
    if(fg){
            sort(a+1,a+1+n);
        for(int i=2;i<=n;i++){
            check(i);
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+1+n);
    ll sum=m;
    ll o=n-1;
    ll cnt=1;
    while(sum>=0&&o){
        if(sum<a[n]-a[o])    break;
        else{
            sum-=a[n]-a[o];
            cnt++;
            o--;
        }
    }
    cout<<cnt;
    return 0;
}
