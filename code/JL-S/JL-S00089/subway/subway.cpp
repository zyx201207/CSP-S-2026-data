#include<bits/stdc++.h>
using namespace std;
struct wow{
	int v,w;
};
int c,n,m,d,q;
int val1[500005];
pair<int,int> val2[500005][25];
int tot[500005];
vector<int>se[505];
vector<wow> fe[500005+505];
int floyd[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(floyd,0x3f,sizeof floyd);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>val1[i];
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,u,w;j<=k;j++){
			cin>>u>>w;
			fe[u+505].push_back({i,w});
			se[i].push_back(u);
			val2[u][++tot[u]].first=i;
			val2[u][tot[u]].second=w;
		}
	}
	for(int i=1+505;i<=m+505;i++){
		for(int j=0;j<fe[i].size();j++){
			for(int k=j+1;k<fe[i].size();k++){
				int vj=fe[i][j].v;
				int vk=fe[i][k].v;
				floyd[vj][vk]=min(floyd[vj][vk],fe[i][j].w+fe[i][k].w);
			}
		}
	}
	for(int i=1;i<=n;i++){
		floyd[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				floyd[i][j]=floyd[j][i]=min(floyd[i][k]+floyd[k][j],min(floyd[i][j],floyd[j][i]));
			}
		}
	}
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=n;j++){
	// 		cout<<i<<' '<<j<<' '<<floyd[i][j]<<'\n';
	// 	}
	// }
	// for(int i=1;i<=m;i++){
	// 	for(int j=1;j<=tot[i];j++){
	// 		cout<<i<<' '<<j<<' '<<val2[i][j].first<<'\n';
	// 	}
	// }
	for(int i=1,l,r;i<=q;i++){
		cin>>l>>r;
		int ans=1e9;
		for(int k1=1;k1<=tot[l];k1++){
			for(int k2=1;k2<=tot[r];k2++){
				ans=min(ans,val2[l][k1].second+val2[r][k2].second+floyd[val2[l][k1].first][val2[r][k2].first]+val1[l]+val1[r]);
				// cout<<floyd[val2[l][k1].first][val2[l][k2].first]<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}