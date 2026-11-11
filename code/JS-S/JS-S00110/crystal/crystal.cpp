#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int a[N],d[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++) d[i]=a[i+1]-a[i];
    ll cnt=0,ans=0;
    for(int i=1;i<n;i++){
        if(cnt>m) break;
        cnt+=d[i]*i;
        ans=i;
    }
    cout<<ans<<endl;
    return 0;
}
