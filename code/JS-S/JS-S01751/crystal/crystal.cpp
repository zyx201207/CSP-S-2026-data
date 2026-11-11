#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mid ((l+r)>>1)
const int MAXN=5e5+10;
int a[MAXN],pre[MAXN];
int n,m,ans=0;
inline int val(int i,int j){
    return a[i]*(i-j)-pre[i-1]+pre[j-1];
}
inline int bnrs(int l,int r){
    int nowpos=r;
    while(l<r){
        if(val(nowpos,mid)<=m)r=mid;
        else l=mid+1;
    }
    return mid;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    for(int i=2;i<=n;i++){
        int tl=bnrs(1,i);
        ans=max(ans,i-tl+1);
    }
    if(ans==1)cout<<0;
    else cout<<ans;
    return 0;
}
