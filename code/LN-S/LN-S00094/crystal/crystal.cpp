#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
int n,m,ans;
ll a[N],val[N],sum[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(i==2)dd=a[i]-a[i-1];
        if(a[i]!=i)vis1=1;
        if(a[i]-a[i-1]!=dd)vis2=1;
    }
    for(int i=1;i<=n;i++){
        val[i]=a[i]-a[i-1];
        if(i==1)val[i]=0;
        sum[i]=sum[i-1]+val[i]*(i-1);
    }
    // for(int i=1;i<=n;i++){
    //     cout<<"val:"<<val[i]<<' ';
    //     cout<<"sum:"<<sum[i]<<' '<<'\n';
    // }
    if(vis1==0){
        for(int i=1;i<=n;i++){
            if(m<sum[i]){
                break;
            }
            else ans=i;
        }
        cout<<ans<<'\n';
    }
    else if(vis1==1&&vis2==0){
        for(int i=1;i<=n;i++){
            if(m<sum[i]){
                break;
            }
            else ans=i;
        }
        cout<<ans<<'\n';
    }
    else if(n<=5000){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(sum[j]-sum[i-1]<=m){
                    // cout<<"i:"<<i<<' '<<"j:"<<j<<' '<<"sum[i]:"<<sum[i]<<' '<<"sum[j]:"<<j<<' '<<'\n';
                    ans=max(ans,j-i+1);
                }
            }
        }
        cout<<ans<<'\n';
    }
    else{
        for(int i=1;i<=n;i++){
            int l=i,r=n;
            int mid=(l+r)>>1;
            while(l<=r){
                if(sum[mid]-sum[l-1]<=m){
                    cnt[i]=max(cnt[i],r-l+1);
                    l=mid+1;
                }
                else r=mid;
            }
        }
        for(int i=1;i<=n;i++)ans=max(ans,cnt[i]);
        cout<<ans<<'\n';
    }
    return 0;
}