#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,kk[505];
long long w[500005],p[505][505];
vector<int>a[500005];
map<int,long long>t[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>kk[i];
		for(int j=1;j<=kk[i];j++){
			int u,v;
			cin>>u;
			a[u].push_back(i);
			cin>>v;
			t[u][i]=v;
		}
	}
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++){
			p[i][j]=1e18;
		}
	}
	for(int i=1;i<=500;i++){
		p[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
			for(int k=j+1;k<a[i].size();k++){
				p[a[i][j]][a[i][k]]=min(p[a[i][j]][a[i][k]],t[i][a[i][j]]+t[i][a[i][k]]);
				p[a[i][k]][a[i][j]]=p[a[i][j]][a[i][k]];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&j!=k&&k!=i){
					p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
				}
			}
		}	
	}
	while(q--){
		long long mn=1e18;
		int u,v;
		cin>>u>>v;
		for(int i=0;i<a[u].size();i++){
			for(int j=0;j<a[v].size();j++){
				mn=min(mn,p[a[u][i]][a[v][j]]+t[u][a[u][i]]+t[v][a[v][j]]);
			}
		}
		cout<<mn+w[u]+w[v]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
