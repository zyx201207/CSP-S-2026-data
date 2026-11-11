#include <bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005],pre[500005];
bool check(int x,int y){
    long long sum=pre[y]-pre[x-1];
    return 1ll*(y-x+1)*a[y]-sum<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        int l=1,r=i,res=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid,i)) res=mid,r=mid-1;
            else l=mid+1;
        }
        if(res) ans=max(ans,i-res+1);
    }
    cout<<ans;
    return 0;
}
