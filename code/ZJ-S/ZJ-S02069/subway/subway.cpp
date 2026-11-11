#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans;
int w[50005];
int a[505][50005],t[505][50005];
vector<pair<int,int>> cnt[50005];
int val[50005],k[50005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			cnt[a[i][j]].push_back({i,t[i][j]});
		}
		for(int j=1;j<=m;j++){
			if(cnt[j].size()==2)val[j]=cnt[j][0].second+cnt[j][1].second;			
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int d=cnt[x].size();
		int e=cnt[y].size();
		int ge=0;
		while(d--){
			int s=cnt[x][d].first;
			int u=cnt[y][e].first;
			int ge1=0;
			for(int i=1;i<=k[s];i++){
				for(int j=1;j<=k[u];j++){
					if(a[s][i]==a[u][j]){
						ge1=a[s][i];
						if(ge){
							if(val[ge]>val[ge1])ge=ge1;
						}
						else{
							ge=ge1;
						}
					}
				}
			}
		}
		ans=w[x]+w[y]+val[ge];
		cout<<ans<<endl;
	}
	return 0;
}
