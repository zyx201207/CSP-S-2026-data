#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int a[505][25];
int k[505];
int t[505][25];
int vis[505];
vector<int> mp[500005],hc[500005];
long long aans[505][505];
vector<int> towh[505];
//n 505 m 500005 d20 q100005;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cin>>c>>n>>m>>d>>q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
//		cin>>w[i];
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
//		cin>>k[i];
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
//			cin>>a[i][j]>>t[i][j];
			scanf("%d%d",&a[i][j],&t[i][j]);
			mp[a[i][j]].push_back(i);
			hc[a[i][j]].push_back(t[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			aans[i][j]=1e16;
		}
	}
	for(int i=1;i<=n;i++){
		aans[i][i]=0;
	}
	
	for(int i=1;i<=m;i++){
		int ll=mp[i].size();
		for(int j=0;j<ll;j++){
			for(int z=j+1;z<ll;z++){
				aans[mp[i][j]][mp[i][z]]=min(aans[mp[i][j]][mp[i][z]],1ll*hc[i][j]+1ll*hc[i][z]);
				aans[mp[i][z]][mp[i][j]]=min(aans[mp[i][z]][mp[i][j]],1ll*hc[i][j]+1ll*hc[i][z]);
				towh[mp[i][j]].push_back(mp[i][z]);
				towh[mp[i][z]].push_back(mp[i][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int z=1;z<n;z++){
				aans[i][z]=min(aans[i][z],aans[i][j]+aans[j][z]);
				aans[z][i]=min(aans[i][z],aans[i][j]+aans[j][z]);
			}
		}
	}
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		long long ans=1e16;
		int ll1=mp[x].size(),ll2=mp[y].size();
		for(int j=0;j<ll1;j++){
			for(int z=0;z<ll2;z++){
				ans=min(ans,aans[mp[x][j]][mp[y][z]]+hc[x][j]+hc[y][z]);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
//		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}