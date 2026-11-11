#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pi pair<int,int>
int c,t;
int x[200005];
int dis[1505][1505];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        cin>>x[1];
        bool f=1;
        for(int i=2;i<=n;i++){
            cin>>x[i];
            if(x[i]-x[i-1]>d) {
                f=0;
            }
        }
        if(!f){
            cout<<0;
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=1e18;
            }
            dis[i][i]=0;
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dis[i][k]==1e18||dis[k][j]==1e18){
                        continue;
                    }
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]+1);
                }
            }
        }
        int cnt=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                    if(i==j) continue;
                int ge=0;
                if(dis[i][j]==1e18) continue;
                for(int k=1;k<=n;k++){
                    if(dis[i][k]==1e18||dis[k][j]==1e18) continue;
                    if(dis[i][k]+dis[k][j]+1==dis[i][j]){
                        ge++;
                    }
                }
                if(ge==2) cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
