#include<bits/stdc++.h>
using namespace std;
int read(){
	int ret=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){if(c=='-') f*=-1;c=getchar();}
	while(c>='0' && c<='9'){ret=ret*10+c-48;c=getchar();}
	return ret*f;
}
int w[505];
vector<int> v[505];
int t[505][505];
bool z[505][505][505];
int c,n,m,d,q;
int dfs(int x,int y,int z1,int zhi){
	if(x==y) return zhi+t[y][z1];
	int ret=2147483647;
	for(auto i:v[x]){
		for(int j=1;j<=n;j++){
			if(j!=z1 && z[x][i][j]){
				ret=min(ret,dfs(i,y,j,zhi+t[x][j]+t[x][z1]));
			}
		}
	}
	return ret;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read(),s=0;
		for(int j=1;j<=k;j++){
			int p=read();
			t[p][i]=read();
			if(s!=0) v[s].push_back(p);
			if(s!=0) z[s][p][i]=1;
			s=p;
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		int minn=2147483647;
		for(auto i:v[x]){
			for(int j=1;j<=n;j++){
				if(z[x][i][j]) minn=min(minn,dfs(i,y,j,t[i][j]));
			}
		}
		cout<<minn+w[x]+w[y]-2<<'\n';
	}
	return 0;
} 
