#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int n,k,a[500005],ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int sum=0,l=1;
    a[0]=a[1];
    for(int i=1;i<=n;i++){
        sum+=(a[i]-a[i-1])*(i-l);
        while(sum>k) sum-=a[i]-a[l],l++;
        ans=max(ans,i-l+1);
    }
    cout<<ans<<'\n';
    return 0;
}