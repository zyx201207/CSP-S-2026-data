#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500010
int n,m,a[N],s[N],ans;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int L=1,R=i;
        while(L<=R){
            int mid=(L+R)>>1;
            if(a[i]*mid-(s[i]-s[i-mid])<=m)
                L=mid+1,ans=max(ans,mid);
            else R=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
