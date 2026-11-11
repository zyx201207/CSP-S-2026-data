#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int ned=0,start=1,ans=0;
    for(int i=1;i<=n;i++){
        ned+=(a[i]-a[i-1])*(i-start);
        while(ned>m){
            ned-=a[i]-a[start];
            start++;
        }
        ans=max(ans,(i-start+1));
    }
    cout<<ans;
    return 0;
}
