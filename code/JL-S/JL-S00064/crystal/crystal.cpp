/*
238
*/

#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define mem(a,b) memset(a,b,sizeof(a));
#define abs_(x) ((x)<0?-(x):(x))
#define sz(x) ((int)(x).size())
#define ull unsigned long long
#define pb push_back
#define fi first
#define se second
using namespace std;
int n,m;
int sum[500005];
int a[500005];
bool check(int len){
    int mn=1e18;
    rep(i,len,n){
        mn=min(mn,a[i]*len-(sum[i]-sum[i-len]));
    }
    return mn<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    rep(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    rep(i,1,n) sum[i]=sum[i-1]+a[i];
    int L=1,R=n;
    while(L<=R){
        int mid=L+R>>1;
        if(check(mid)) L=mid+1;
        else R=mid-1;
    }
    cout<<R;
    return 0;
}
