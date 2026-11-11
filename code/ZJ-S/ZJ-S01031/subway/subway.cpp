#include<bits/stdc++.h>
#define int long long
#define M 10000000000000000
using namespace std;
int c,n,m,d,q;
int w[1000000];
int k[1001];
vector<int>edge[500005],tim[500005];
int dp[1001][1001];
int s[1000000];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)dp[i][j]=M;
            else dp[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int p,o;
            cin>>p>>o;
            edge[p].push_back(i);
            tim[p].push_back(o); 
            s[p]++;  
        }

    }
    for(int x=1;x<=m;x++){
        if(s[x]>=2){
            for(int i=0;i<s[x];i++){
                for(int j=0;j<s[x];j++){
                	
                    dp[edge[x][i]][edge[x][j]]=min(dp[edge[x][i]][edge[x][j]],tim[x][i]+tim[x][j]);
                }
            }
        }
    }
     for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;cin>>x>>y;
        int ans=M;
         for(int i=0;i<s[x];i++){
            for(int j=0;j<s[y];j++){
                 ans=min(dp[edge[x][i]][edge[y][j]]+tim[x][i]+tim[y][j],ans);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
}
