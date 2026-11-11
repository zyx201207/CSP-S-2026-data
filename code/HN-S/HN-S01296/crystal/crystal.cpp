#include<bits/stdc++.h>
#define int long long
#define L(i,j,k) for(int i=(j);i<=(k);i++)
#define R(i,j,k) for(int i=(j);i>=(k);i--)
using namespace std;
const int M = 5e5+5;
int n,m,ans,l = 1;
int a[M],pre[M];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    L(i,1,n)cin>>a[i];
    sort(a+1,a+n+1);
    L(i,1,n)pre[i] = pre[i-1]+a[i];
    L(i,1,n){
        while((i-l+1)*a[i]-(pre[i]-pre[l-1])>m)l++;
        ans = max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}