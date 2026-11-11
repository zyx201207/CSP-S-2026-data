#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],pre[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    int res=1;
    for(int i=2;i<=n;i++){
        int L=1,R=i-1,ans=-1;
        while(L<=R){
            int mid=(L+R)>>1;
            if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m){
                ans=mid;R=mid-1;
            }else L=mid+1;
        }
        if(ans==-1) continue;
        else res=max(res,i-ans+1);
    }
    cout<<res<<'\n';
    return 0;
}