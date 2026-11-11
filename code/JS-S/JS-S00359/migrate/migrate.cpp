#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[2000010],dp[2000010],m,dp2[2000010],pt,pt2;
int dis(int a,int b){
    return labs(a-b);
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c;
    cin>>c;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i];
        pt=1;
        dp[1]=dp2[1]=0;
        pt2=1;
        for(int i=2;i<=n;i++)dp[i]=dp2[i]=0;
        for(int i=2;i<=n;i++){
            while(pt2<=pt&&dis(a[pt2],a[i])>m)pt2++;
            if(pt<pt2){
                pt++;
                continue;
            }else{
                dp[i]=dp[pt2]+1;
                pt++;
            }
        }
        stable_sort(a+1,a+n+1);
        int b=unique(a+1,a+n+1)-a-1;
        cout<<n-b<<'\n';
    }
    return 0;
}