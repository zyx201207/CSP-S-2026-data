#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5e5+5;
ll a[N],m,ans;
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    //bf
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        ll cnt=0;ll val=m;
        for(int j=i;j>=1&&val>=0;j--){
            ll d=a[i]-a[j];
            val-=d;cnt++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<"\n";
    return 0;
}
