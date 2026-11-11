#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=5e5+5;
int n,m,ans=1;
ll a[N],dlt;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2,l=1;i<=n;i++){
        dlt+=(a[i]-a[i-1])*(i-l);
        while(dlt>m)dlt-=a[i]-a[l++];
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
