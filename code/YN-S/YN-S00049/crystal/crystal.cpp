#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n,ans,cnt[N],t;ll m,a[N],b[N],s[N];
inline int gt(int x){return lower_bound(b+1,b+t+1,x)-b;}
int main(){
    freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
    sort(b+1,b+n+1),t=unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=n;i++)cnt[gt(a[i])]++;
    for(int i=1;i<=t;i++)s[i]=s[i-1]+1ll*b[i]*cnt[i],cnt[i]+=cnt[i-1];
    ans=cnt[1];
    for(int i=2;i<=t;i++){
        int l=1,r=i,mid,res;
        while(l<=r){
            mid=(l+r)/2;ll sum=1ll*(cnt[i]-cnt[mid-1])*b[i]-s[i]+s[mid-1];
            if(sum<=m)res=mid,r=mid-1;
            else l=mid+1;
        }
        int tmp=cnt[i]-cnt[res-1];
        if(res>1){
            ll u=m-(1ll*tmp*b[i]-s[i]+s[res-1]);
            tmp+=u/(b[i]-b[res-1]);
        }
        ans=max(ans,tmp);
    }
    cout<<ans;
}
//最后一堆相等的能量肯定是a[i]
