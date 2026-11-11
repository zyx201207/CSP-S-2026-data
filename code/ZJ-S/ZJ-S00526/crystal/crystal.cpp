#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,ans=1;
ll m,a[500005],lst;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=2,j=1;i<=n;i++){
        lst+=1ll*(i-j)*(a[i]-a[i-1]);
        while(lst>m&&j<i)lst-=1ll*(a[i]-a[j]),j++;
        ans=max(ans,i-j+1);
    }
    cout<<ans;
    return 0;
}