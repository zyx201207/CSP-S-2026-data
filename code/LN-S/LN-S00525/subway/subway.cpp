#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N=505,M=2e4+5,K=2e4+5;
int n,m,d,q;
int w[M],a[N][K],t[N][K],k[N];
int ans=ULLONG_MAX,sum=0;
bool vis[M];
void cal(int x,int y,int cost=0,int from=0){
	if(x==y){
		ans=min(ans,cost+sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(from==i) continue;
		bool flag=false;
		int tmp=0;
		for(int j=1;j<=k[i];j++){
			if(a[i][j]!=x) continue;
			flag=true;
			tmp=t[i][j];
			sum+=tmp;
			break;
		}
		if(!flag) continue;
		for(int j=1;j<=k[i];j++){
			if(vis[a[i][j]]==0){
				vis[a[i][j]]=1;
				cal(a[i][j],y,cost+=t[i][j],i);
				vis[a[i][j]]=0;
			}
		}
		sum-=tmp;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=LLONG_MAX;
		memset(vis,0,sizeof(vis));
		vis[x]=1;
		cal(x,y);
		cout<<w[x]+w[y]+ans<<"\n";
	}
	return 0;
}
