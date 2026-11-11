#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long l=1,now=0;
    for(long long r=1;r<=n;r++){
        now=now+(a[r]-a[r-1])*(r-l);
        while(l<=r&&now>m)l++,now=now-a[r]+a[l-1];
        ans=max(ans,r-l+1);
    }
    cout<<ans<<'\n';
    return 0;
}
