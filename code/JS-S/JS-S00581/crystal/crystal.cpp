#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],s[N];
bool check(int len){
    for(int l=1;l+len-1<=n;l++){
        int r=l+len-1,mid=(l+r)>>1;
        if((r-l+1)*a[r]-(s[r]-s[l-1])<=m)
            return 1;
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    int l=1,r=n+1,mid;
    while(l+1<r){
        mid=(l+r)>>1;
        if(check(mid)) l=mid;
        else r=mid;
    }
    cout<<l<<'\n';
    return 0;
}