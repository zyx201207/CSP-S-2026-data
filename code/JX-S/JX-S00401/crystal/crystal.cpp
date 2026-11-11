#include<bits/stdc++.h>
#define L(i,j,k) for(int i=(j);i<=(k);++i)
#define R(i,j,k) for(int i=(j);i>=(k);--i)
#define int long long
using namespace std;
int n,m;
const int N=5e5+10;
int a[N];


signed main(){
    //crystal
   // freopen("crystal3.in","r",stdin);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    L(i,1,n)cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0;
    int l=1;int sum=0;
    L(r,2,n){
        sum+=(r-l)*(a[r]-a[r-1]);
        while(l<r&&sum>m){
            sum-=(a[r]-a[l]);
            ++l;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
