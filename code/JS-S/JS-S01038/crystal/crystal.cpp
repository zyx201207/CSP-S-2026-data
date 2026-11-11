#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
#define mkp make_pair
#define pb push_back
#define y0 y000
#define y1 y111
#define j0 j000
#define j1 j111
typedef long long ll;
typedef unsigned long long ull;
ll arr[500005];
ll psm[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;ll m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>arr[i];
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n;i++)psm[i]=psm[i-1]+arr[i];
    int l=1,r=n+1;
    while(l<r){
        int mid=(l+r)>>1;
        ll mn=m+1;
        for(int i=mid;i<=n;i++)mn=min(mn,arr[i]*mid-(psm[i]-psm[i-mid]));
        if(mn<=m)l=mid+1;
        else r=mid;
    }
    cout<<l-1;
    return 0;
}
//peimuda bless me
//MatrixGroup bless me
//hyman00 bless me
//UKBwyx bless me
//luckyclover bless me
//He_XY bless me
//daisybunny bless me
//chenmohan bless me
//xuanxuanni bless me
//Tk_hash bless me
//chennie bless me
//placeholder bless me
//Cubber bless me
//rp++