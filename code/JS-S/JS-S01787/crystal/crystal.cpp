#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[500005],m,b[500005],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)b[i]=a[i]-a[i-1];
    for(int i=n;i>=1;i--){
        ll j=1,sum=0,sum1=0;
        while(sum<=m&&i-j+1>0){
            sum1+=b[i-j+1];
            sum+=sum1;
            j++;
        }
        j--;
        ans=max(ans,j);
        if(ans>=i)i=0;
    }
    cout<<ans;
    return 0;
}
