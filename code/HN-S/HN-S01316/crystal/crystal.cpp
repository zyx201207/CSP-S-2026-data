#include<bits/stdc++.h>
#define int long long
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans=0,s[N];
int check(int mid,int x){
    return a[x]*mid-(s[x]-s[x-mid]);
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;++i){
        int L=1,R=i,res=-1;
        while(L<=R){
            int mid=(L+R)/2;
            if(check(mid,i)<=m)res=mid,L=mid+1;
            else R=mid-1;
        }
        ans=max(ans,res);
    }
    cout<<ans<<'\n';
    return 0;
}