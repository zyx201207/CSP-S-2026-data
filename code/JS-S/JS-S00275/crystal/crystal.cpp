#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500001],c[500001],pre[500001],ans,ansi;
int m;
bool check(int l){
    for(int i=l;i<=n;i++){
        if(l*a[i]*1ll-(pre[i]*1ll-pre[i-l]*1ll)*1ll<=m*1LL){
               // cout<<l*a[i]*1ll-(pre[i]*1ll-pre[i-l]*1ll)*1ll<<'\n';
            return 1;
        }
    }
    return 0;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    //cout<<check(4)<<'\n';
    cout<<l;
    return 0;
}
//in fact ,i am JS-J00388.
