#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long presum[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        presum[i]=presum[i-1]+a[i];
    }
    sort(a+1,a+n+1);
    long long cishu=0;
    long long ans[500010];
    for(int i=1;i<=n;i++){
        cishu=0;
        cishu=(a[i]*(i-1))-presum[i-1];
        if(cishu>m){
            ans[i]=0;

        }else{
            ans[i]=i;
        }
    }
    long long maxn=-10000007;
    for(int i=1;i<=n;i++){
        maxn=max(maxn,ans[i]);
    }cout<<maxn;
    return 0;
}
