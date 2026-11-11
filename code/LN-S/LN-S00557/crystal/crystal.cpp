#include<bits/stdc++.h>
using namespace std;
long long a[1000001],f[1000001],ans=-1e18;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long sum=m;
    f[1]=1;
    for(long long i=2;i<=n;i++){
        long long b=(i-1)*(a[i]-a[i-1]);
        if(sum>b){
            sum-=b;
            f[i]=i;
        }else if(sum==b){
            sum-=b;
            f[i]=i;
        }else{
            sum-=b;
            break;
        }
    }
    for(long long i=1;i<=n;i++){
        if(f[i]>ans){
            ans=f[i];
        }
    }
    cout<<ans;
    return 0;
}