#include <bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=5e5+5;
int n,m,a[N],sum[N];
bool check(int mid){
    bool flag=0;
    rep(i,0,n-mid+1){//i,i+mid-1
        int res=a[i+mid-1]*mid-sum[i+mid]+sum[i];
        if(res<=m)return 1;
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    rep(i,0,n)cin>>a[i];
    sort(a,a+n);
    rep(i,0,n)sum[i+1]=sum[i]+a[i];
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l;
    return 0;
}
