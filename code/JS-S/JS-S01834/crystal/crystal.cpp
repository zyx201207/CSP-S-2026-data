#include<bits/stdc++.h>
#define int __int128
#define endl '\n'
#define inf 1234567890
#define mod 998244353
#define N 500005
using namespace std;
int n,m,ans;
int a[N],q[N];

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long asdf,ghjk;
    cin>>asdf>>ghjk;
    n=asdf,m=ghjk;
    for(int i=1;i<=n;i++){
        long long x;cin>>x;
        a[i]=x;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) q[i]=a[i]-a[i-1];
    for(int i=2;i<=n;i++) q[i]=q[i-1]+q[i];
    int l=0,r=1;
    int costnow=0;
    while(l<n){
        l++;
        int len=r-l+1;
        while((a[r+1]-a[r])*len+costnow<=m&&r<n){
            costnow+=(a[r+1]-a[r])*len;
            r++,len++;
        }
        costnow-=(q[r]-q[l]);
        ans=max(ans,len);
    }
    long long asdfghjkl=ans;
    cout<<asdfghjkl;
    return 0;
}