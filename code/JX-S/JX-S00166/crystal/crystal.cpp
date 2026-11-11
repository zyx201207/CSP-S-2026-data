#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod=998244353;
const int N=500020;
int n,m,ans;
int a[N];
bool check(int x){
    int cnt=0;
    for(int i=1;i<x;i++){
        cnt+=(a[x]-a[i]);
    }
    if(cnt<=m)return 1;
    for(int i=2;i<=n-x+1;i++){
        cnt-=(a[x+i-2]-a[i-1]);
        cnt+=(x-1)*(a[x+i-1]-a[x+i-2]);
        if(cnt<=m)return 1;
    }
    return 0;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int l=1,r=n,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1;
        }else{
            r=mid;
        }
    }
    if(!check(l))l--;
    cout<<l;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _=1;
    //cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
