#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+10;
ll n,m,a[maxn],ans[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    a[0]=-1000000000005;
    for(int i=1;i<=n;i++){
        ll x=m;
        int l=i-1;
        while(x>=a[i]-a[l]){
            ans[i]++;
            x-=a[i]-a[l];
            l--;
        }
    }
    ll ma=0;
    for(int i=1;i<=n;i++){
        ma=max(ma,ans[i]);
    }
    cout<<ma+1;
    return 0;
}
