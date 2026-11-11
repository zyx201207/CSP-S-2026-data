#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,aa[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>aa[i];
    for(int i=1;i<=m;i++){
        sort(aa+1,aa+n+1);
        aa[1]++;
    }
    int ans=INT_MIN,t=1;
    sort(aa+1,aa+n+1);
    for(int i=2;i<=n;i++){
        if(aa[i]==aa[i-1]){
            t++;
        }else{
            ans=max(ans,t);
            t=0;
        }
    }
    ans=max(ans,t);
    cout<<ans;
    return 0;
}
