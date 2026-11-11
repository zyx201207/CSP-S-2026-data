#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
long long a[500005];
long long sum[500005];
bool check(int l,int r){
    long long su=sum[r]-sum[l-1];
    su=a[r]*(r-l+1)-su;
    return su>m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for(long long i=1,j=1;j<=n;j++){
        while(check(i,j))i++;
        ans=max(ans,j-i+1);
    }
    cout<<ans;
    return 0;
}
