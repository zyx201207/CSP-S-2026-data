#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1,j=1;i<=n;i++){
        sum+=(i-j)*(a[i]-a[i-1]);
        while(j<i&&sum>m){
            sum-=a[i]-a[j];
            j++;
        }
        ans=max(ans,i-j+1ll);
    }
    cout<<ans;
}
