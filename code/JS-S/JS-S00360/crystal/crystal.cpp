#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],ans,sum;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=n,j=n;i;i--){
        if(j>i)j--;
        while(j>1&&sum+a[i]-a[j-1]<=m){
            sum+=a[i]-a[j-1];
            j--;
        }ans=max(ans,i-j+1);
        sum-=(i-j)*(a[i]-a[i-1]);
    }
    cout<<ans;
    return 0;
}
