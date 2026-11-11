#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
   freopen("migrate.in", "r", stdin);
   freopen("migrate.out", "w", stdout);
    int c, t, n, d;
    int a[200005];
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int ans=0;
        int pre = 0;
        for(int i=1;i<=n;i++){
            if(i+1<n&&a[i+1]-a[i]<=d&&a[i+2]-a[i]>d)pre++;
            else if(i+3<=n&&a[i+1]-a[i]<=d&&a[i+2]-a[i]<=d&&a[i+3]-a[i]>d&&a[i+3]-a[i+1]<=d){
                ans++;
                int t=i+1;
                i+=3;
                ans+=pre,pre=0;
                while(i+2<=n&&a[i+1]-a[i]<=d&&a[i+2]-a[i]>d){
                    ans++,i++;
                }
                i=t;
            }
            else pre=0;
        }
        cout<<ans<<'\n';
    }
    return 0;
}

