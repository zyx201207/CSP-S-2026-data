#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl '\n'
#define int long long
#define inf (1ll*0x3f3f3f3f3f3f3f3f)
using namespace std;
const int N=505,M=5e5+5;
int dp[N][N];
int w[M];
struct node{
    int x,y;
};
vector<node>a[M];
int c,n,m,d,q;
signed main(void){
	IOS;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=inf;
        }
    }
    for(int i=1;i<=n;i++)dp[i][i]=0;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,t;
            cin>>x>>t;
            a[x].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(node j:a[i]){
            for(node k:a[i]){
                if(j.x==k.x)continue;
                dp[j.x][k.x]=min(dp[j.x][k.x],j.y+k.y);
                dp[k.x][j.x]=min(dp[k.x][j.x],j.y+k.y);
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
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=inf;
        for(node i:a[x]){
            for(node j:a[y]){
                ans=min(ans,dp[i.x][j.x]+w[x]+w[y]+i.y+j.y);
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
