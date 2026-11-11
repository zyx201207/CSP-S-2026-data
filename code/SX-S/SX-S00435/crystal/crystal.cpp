#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+50;
int n,m,ans;
int a[N],sum[N];
bool check(int l,int r){
    if((r-l+1)*a[r]-(sum[r]-sum[l-1])<=m)return 1;
    else return 0;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int L=i,R=n;
        int res=0;
        while(L<=R){
            int mid=(L+R)/2;
            if(check(i,mid)){
                res=mid-i+1;
                L=mid+1;
            }else R=mid-1;
        }
        ans=max(ans,res);
    }
    cout<<ans;

    return 0;
}