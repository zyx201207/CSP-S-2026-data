#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,mx=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    a[0]=a[1];
    for(int r=1,l=1,sum=0;r<=n;r++){
        sum+=(a[r]-a[r-1])*(r-l);
        while(sum>m)sum-=a[r]-a[l++];
        mx=max(mx,r-l+1);
    }
    cout<<mx;
    return 0;
}
