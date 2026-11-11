#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N=1e6+10,MOD=1e9+7;
int c,n,m,d,p,w[N],k[510],a[510][1010],t[510][1010],flag=1,dp[1010],vis[510][1010];
signed main(){
	IOS
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			if(t[i][j]!=t[1][1]){
				flag=0;
			}
		}
	}
	while(p--){
		memset(dp,0x3f,sizeof(dp));
		memset(vis,0,sizeof(vis));
		int x,y,now;
		queue<long long> q;
		cin>>x>>y;
		dp[x]=w[x];
		q.push(x);
		while(q.size()){
			now=q.front();
			q.pop();
			for(int i=1;i<=n;i++){
				for(int j=1;j<=k[i];j++){
					if(a[i][j]==now&&!vis[i][j]){
						for(int g=1;g<=k[i];g++){
							dp[a[i][g]]=min(dp[now]+t[i][j]+t[i][g],dp[a[i][g]]);
							q.push(a[i][g]);
							vis[i][j]=1;
						}
						break;
					}
				}
			}
		}
		cout<<dp[y]+w[y]<<endl;
	}
	return 0;
}
