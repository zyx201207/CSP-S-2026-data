#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+9;
int a[maxn],d[maxn],s[maxn];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    for(int i=1;i<=n;i++){
        d[i]=a[1]-a[i];
        s[i]=s[i-1]+d[i];
    }
    //for(int i=1;i<=n;i++) cout<<s[i]<<' ';
    int r=1,mx=0;
    for(int l=1;l<=n;l++){

        while(r<=n&&s[r]-s[l-1]-(r-l+1)*(a[1]-a[l]) <= m) r++;
        r--;
        //cout<<l<<' '<<r<<endl;
        mx=max(mx,r-l+1);
    }
    cout<<mx;

    return 0;
}
