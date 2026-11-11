#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500010;
ll n,a[N],b[N],m,num[N];
bool check(ll x)
{
    ll l=1,r=x-1,sum=0;
    for(int i=1;i<x;i++){
        sum+=b[i]*i;
    }
    if(sum<=m) return true;
    for(int i=x;i<n;i++){
        sum-=(num[r]-num[l-1]);
        sum+=b[i]*(x-1);
        if(sum<=m){
			//cout<<sum<<"\n";
			return true;
		}
        l++,r++;
    }
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    //cout<<m<<"\n";
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++) b[i]=a[i+1]-a[i],num[i]=num[i-1]+b[i];
    //for(int i=1;i<=10;i++) cout<<a[i]<<" ";
    //cout<<"\n";
    ll l=1,r=n;
    while(l<r)
    {
        ll mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
        //cout<<mid<<"\n";
    }
    cout<<l;
}
