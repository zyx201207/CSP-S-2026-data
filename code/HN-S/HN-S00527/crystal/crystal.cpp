#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
int n,m;
ll a[N],d[N];
ll ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) d[i]=a[i]-a[i-1];
    for(int i=2;i<=n;i++){
        if(d[i]*(i-1)<=m){
            m-=d[i]*(i-1);
            ans=i;
        }
        else break;
    }
    cout<<ans;
    return 0;
}
