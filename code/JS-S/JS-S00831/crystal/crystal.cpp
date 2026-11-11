#include<bits/stdc++.h>
using namespace std;
long long n,m,a[514114],s[514114],p=1,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for(long long i=1;i<=n;i++){while(a[i]*(i-p+1ll)-s[i]+s[p-1]>m&&p<i)p++;ans=max(ans,i-p+1);}
    cout<<ans;
    return 0;
}
