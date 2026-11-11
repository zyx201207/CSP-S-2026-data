#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500010;
int a[N],dif[N],sum[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=1;i<n;i++){
        dif[i]=a[i]-a[i-1];
    }
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+dif[i];
    }
    int l=1,r=0,cur=0,ans=0;
    for(;r<n;){
        r++;
        cur+=(r-l+1)*(dif[r]);
        while(cur>m){
            cur-=(sum[r]-sum[l-1]);
            l++;
        }
        ans=max(ans,r-l+2);
    }
    cout<<ans;
}
