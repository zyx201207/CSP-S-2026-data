#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,k) for(ll i=j;i<=k;i++)
ll a[500005],mx=1,p=0,ans[500005],mm[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    f(i,1,n) cin>>a[i];
    sort(a+1,a+n);
    f(i,2,n){
        ans[i]=ans[i-1]+mm[i-1]*(a[i]-a[i-1])+a[i]-a[i-1];
        mm[i]=mm[i-1]+1;
        while(m<ans[i]){
            ans[i]-=a[i];
            ans[i]+=a[i-mm[i]];
            mm[i]--;
        }
        mx=max(mm[i]+1,mx);
    }
    cout<<mx;
}
