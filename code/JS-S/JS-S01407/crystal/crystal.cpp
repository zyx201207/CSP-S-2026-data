#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m;
LL a[500005],sum[500005],maxn;
LL l,r,ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
      sum[i]=sum[i-1]+a[i];

    l=1,r=1;
    maxn=-1e18;
    for(; r<=n&& l<=n;){
        if(l>=r){
            r++;
            continue;
        }
        maxn=a[r];

        LL cnt=r-l+1;
        cnt*=maxn;


        cnt-=sum[r]-sum[l-1];
       // cout<<sum[r]<<' ';//-sum[l-1]<<' ';
       // cout<<cnt<<' ';
        if(cnt>m){
            l++;
        }else{
            ans=max(ans,r-l+1);
            r++;
        }

    }
    cout<<ans;
}
