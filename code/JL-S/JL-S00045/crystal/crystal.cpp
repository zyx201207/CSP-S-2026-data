#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50005],ans;
int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        long long tc,ta=1,mm=m;
        for(int j=i-1;j>=1;j--){
            tc=0;
            tc+=a[i]-a[j];
            mm-=tc;
            if(mm<0)break;
            ta++;
        }
        ans=max(ans,ta);
    }
    cout<<ans;

return 0;
}
