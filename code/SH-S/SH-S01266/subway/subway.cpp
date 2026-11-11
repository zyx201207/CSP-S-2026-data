#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,w[200005],ans=0x3f3f3f3f;
int x,y;
struct node{
	int u,t;
};
int g[505][40005];
vector<int> s[200005];
int f[505][505];
bool f1,f2;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1,u,t;j<=k;j++){
			cin>>u>>t;
			g[i][u]=t;
			s[u].push_back(i);
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++){
		if(s[i].size()>1){
			for(int j=0;j<s[i].size();j++){
				for(int k=j+1;k<s[i].size();k++){
					f[s[i][j]][s[i][k]]=f[s[i][k]][s[i][j]]=min(f[s[i][j]][s[i][k]],g[s[i][j]][i]+g[s[i][k]][i]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		f[i][i]=0;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		ans=0x3f3f3f3f;
		for(int i=0;i<s[x].size();i++){
			for(int j=0;j<s[y].size();j++){
				ans=min(ans,f[s[x][i]][s[y][j]]+g[s[x][i]][x]+g[s[y][j]][y]);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
