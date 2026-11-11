#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[510],t[510][500010],f[510][510];
vector<pair<int,int> > b[500010];
int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
void write(int x){
	if(!x) return ;
	write(x/10);
	putchar(x%10+'0');
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		int cnt=read();
		for(int j=1;j<=cnt;j++){
			int v=read();
			t[i][v]=read();
			b[v].push_back(make_pair(i,t[i][v]));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<b[i].size();j++){
			for(int k=0;k<b[i].size();k++){
				if(j==k) f[b[i][j].first][b[i][k].first]=0;
				else f[b[i][j].first][b[i][k].first]=min(f[b[i][j].first][b[i][k].first],b[i][j].second+b[i][k].second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int u=read(),v=read();
		int ans=1e18;
		for(int i=0;i<b[u].size();i++){
			for(int j=0;j<b[v].size();j++){
				ans=min(ans,t[b[u][i].first][u]+t[b[v][j].first][v]+f[b[u][i].first][b[v][j].first]);
			}
		}
		ans+=w[u]+w[v];
		if(ans==0) putchar('0');
		else write(ans);
		putchar('\n');
	}
	return 0;
}
