#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
const int N=500005;
int n;
ll m;
ll a[N];
ll d[N];
ll maxn=-1e18;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    if(n==1){
        cout << 1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        d[i]=a[i]-a[i-1];
    }
    ll l=1;
    ll val=0;
    for(ll r=2;r<=n;r++){
        val+=(r-l)*d[r];
        while(val>m){
            // cout << "aaa";
            l++;
            val-=a[r]-a[l];
        }
        // cout << val<<"---"<<l<<"--"<<r<<"\n";
        maxn=max(maxn,(ll)r-l+1);
        
        
    }
    cout << maxn;
    return 0;
}