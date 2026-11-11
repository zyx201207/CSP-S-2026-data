#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,k,n) for (int i=(k);i<=(n);i++)
#define R(i,k,n) for (int i=(k);i>=(n);i--)
#define pu push_back
#define mpr make_pair
#define lowb(x) (x&(-x))
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
const int N=5e5+10;
int n,m;
int a[N];
int ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    F(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    int zhi=n;
    int sum=a[n];
    R(i,n,1){
        while (zhi && a[i]*(i-zhi+1)-sum<=m) zhi--,sum+=a[zhi];
        ans=max(ans,i-zhi);
        sum-=a[i];
    }
    cout<<ans;
    return 0;
}
/*
5 5
1 2 4 8 9
*/