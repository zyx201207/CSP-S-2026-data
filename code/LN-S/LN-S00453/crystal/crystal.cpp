#include<bits/stdc++.h>
using namespace std;
#define int long long
#define chennie return
#define bless 0
#define me ;
int n,m,a[500005],b[500005],ans=1;
bool check(int x,int y){
    if((x-1)*a[y]-(b[y-1]-b[y-x])<=m)return 1;
    else return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid,i))l=mid+1;
            else r=mid-1;
        }
        ans=max(ans,l-1);
    }
    cout<<ans;
    chennie bless me
}
