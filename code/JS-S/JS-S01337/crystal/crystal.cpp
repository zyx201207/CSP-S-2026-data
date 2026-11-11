#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],b[N],c[N],ans;
int f(int l,int r){
    return c[l]-c[r+1]-(r-l+1)*b[r+1];
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in" ,"r",stdin );
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n-1;i++)b[i]=a[i+1]-a[i];
    for(int i=n-1-1;i>=1;i--)b[i]+=b[i+1];
    c[n-1]=b[n-1];
    for(int i=n-1-1;i>=1;i--)c[i]=b[i]+c[i+1];
    for(int l=1,r=1;r<=n-1;r++){
        while(f(l,r)>m)l++;
        ans=max(ans,r-l+1);
    }
    cout<<ans+1<<'\n';
    return 0;
}

