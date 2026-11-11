#include<bits/stdc++.h>
using namespace std;
int c,t,a[2000005];
set<int> se;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        int n,d;cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        vector<int> v;
        for(int i=1;i<=n-2;i++){
            v.push_back(a[i+2]-a[i]);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+2;j<=n;j++){
                int cnt=0;
                for(int l=i-1;l<=j-3;l++){
                    if(v[l]<=d) cnt++;
                }
                if(cnt==2) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
