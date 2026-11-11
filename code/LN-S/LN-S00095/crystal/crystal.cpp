#include<bits/stdc++.h>
using namespace std;
long long n,m;long long a[500005];int ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=1;long long sum=0;
    while(r<=n){
        while(m-sum>=(a[r+1]-a[r])*1LL*(r-l+1) && r<n)sum+=(a[r+1]-a[r])*1LL*(r-l+1),r++;
        ans=max(ans,r-l+1);
        if(r==n)break;
        sum-=a[r]-a[l];l++;
    }
    cout<<ans;
}
