#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],sum[N],d[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long ans=0;
    for(long long i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for(long long i=2;i<=n;i++){
        long long l=1,r=i-1;
        long long mid=(l+r)/2;
        long long sum1=a[i]*(i-1);
        while(l<=r){
            mid=(l+r)/2;
            long long k=(sum1-sum[i-1])-(a[i]*mid-sum[mid]);
            k=k+a[i]-a[mid];
            if(k<=m){
                ans=max(ans,i-mid+1);
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
