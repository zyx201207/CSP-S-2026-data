#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500010;
int n;
ll m,a[N],sum[N];
map <ll,int> b;
int main(){
    freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int mid,l=1,r=i-1,res=i;
        while(l<=r){
            mid=(l+r)>>1;
            if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m){
                r=mid-1;res=mid;
            }
            else l=mid+1;
        }
        ans=max(ans,i-res+1);
    }
    cout<<ans<<'\n';
    return 0;
}