#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],dff[N],sum[N];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)dff[i]=a[i]-a[i-1];
    for(int i=2;i<=n;i++)sum[i]=sum[i-1]+dff[i];
    int mx=1,tot=0,l=2,r=1;
    for(;r<=n;r++){
        tot+=dff[r]*(r-l+1);
        //cout<<'a'<<l<<' '<<r<<' '<<tot<<'\n';
        while(tot>m&&l<=r){
            tot-=(sum[r]-sum[l-1]),l++;
        }
        mx=max(mx,r-l+2);
        //cout<<l<<' '<<r<<' '<<tot<<'\n';
    }
    cout<<mx<<'\n';
    return 0;
}
/*
5 8
-3 -1 2 2 7


4
*/
