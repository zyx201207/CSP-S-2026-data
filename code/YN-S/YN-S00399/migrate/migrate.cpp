#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e6+5,inf=2e18;
ll c,t,n,d,x[N];

int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        vector<vector<int> > dis(n+1,(vector<int>(n+1,inf)));
        vector<vector<int> > cnt(n+1,(vector<int>(n+1,0)));
        for(int i=1;i<=n;i++){
            cin>>x[i];
            dis[i][i]=0;
        }
        for(int i=1;i<=n;i++){
            ll id=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
            id=min(id,n);
            for(int j=i+1;j<=id;j++){
                dis[i][j]=1;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=i+1;k<j;k++){
                    if(dis[i][k]==inf||dis[k][j]==inf){
                        continue;
                    }
                    if(dis[i][k]+dis[k][j]==dis[i][j]){
                        cnt[i][j]++;
                    }
                    if(dis[i][k]+dis[k][j]<dis[i][j]){
                        dis[i][j]=dis[i][k]+dis[k][j];
                        cnt[i][j]=1;
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(cnt[i][j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
