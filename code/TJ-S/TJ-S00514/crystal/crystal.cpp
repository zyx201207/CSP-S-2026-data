#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m,a[500009];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=n,r=n,ans=0;
    ll nowcost=0;
    for (;r;r--){
        if (r!=n)nowcost-=(a[r+1]-a[r])*(r-l+1);
        if (r<l)l=r,nowcost=0;
        while (l>1&&nowcost+(a[r]-a[l-1])<=m){l--,nowcost+=(a[r]-a[l]);}
        //cout<<r<<" "<<l<<" "<<nowcost<<"\n";
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
