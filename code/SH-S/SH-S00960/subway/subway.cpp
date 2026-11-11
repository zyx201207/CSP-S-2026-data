#include<bits/stdc++.h>
using namespace std;
long long floyd[505][505],c,n,m,d,q,w[500005];
vector<pair<long long,long long>> point[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++){
		cin>>w[i];
	}for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			floyd[i][j]=1e12;
		}
		int k;
		cin>>k;
		for(int j=1,p,l; j<=k; j++){
			cin>>p>>l;
			point[p].push_back({i,l});
		}
	}
	for(int i=1; i<=n; i++){
		floyd[i][i]=0;
	}
	for(int r=1; r<=m; r++){
		for(int u=0; u<point[r].size(); u++){
			for(int v=0; v<point[r].size(); v++){
				long long s=point[r][u].first,t=point[r][v].first,l1=point[r][u].second,l2=point[r][v].second;
				floyd[s][t]=min(floyd[s][t],l1+l2);
			}
		}
	}for(int mid=1; mid<=n; mid++){
		for(int l=1; l<=n; l++){
			for(int r=1; r<=n; r++){
				floyd[l][r]=min(floyd[l][r],floyd[l][mid]+floyd[mid][r]);
			}
		}
	}
	while(q--){
		long long l,r;
		cin>>l>>r;
		long long minn=1e16;
		for(int u=0; u<point[l].size(); u++){
			for(int v=0; v<point[r].size(); v++){
				long long s=point[l][u].first,t=point[r][v].first,l1=point[l][u].second,l2=point[r][v].second;
				minn=min(minn,l1+l2+floyd[s][t]);
			}
		}cout<<minn+w[l]+w[r]<<endl;
	}
	return 0;
}
