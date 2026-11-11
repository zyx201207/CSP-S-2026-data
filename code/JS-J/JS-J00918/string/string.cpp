#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+3;
int a[N];
char c[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];

    ll ans=0;
    int l=1,r=n,p=1;
    while(r-l>=0){
        int t=min(a[l],a[r]);
        if(c[l]!=c[r]) ans+=t,cout<<c[l]<<c[r]<<t<<endl;
        if(a[l]>a[r]) a[l]-=t,r--;
        else if(a[l]==a[r]) l++,r--;
        else if(a[l]<a[r]) l++,a[r]-=t;
    }
    cout<<ans<<endl;
    return 0;
}
