#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005]={0},sum,j,ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n,less<int>());
    for(int i=1;i<=n;i++){
        sum=0;
        j=i;
        while(sum<=m&&--j>=1)sum+=a[i]-a[j];
        ans=max(ans,i-j);
    }
    cout<<ans;
    return 0;
}
