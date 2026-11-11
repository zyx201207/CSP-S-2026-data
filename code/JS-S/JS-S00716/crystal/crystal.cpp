#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,sum,ans,a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    ll l=1,r=1;
    for(;r<=n;r++){
        sum+=a[r];
        while(l<=r&&m<(r-l+1)*a[r]-sum)
            sum-=a[l],l++;
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
