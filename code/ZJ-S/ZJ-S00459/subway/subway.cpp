#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,n,m,d,q,w[511451],dis[514][514],s[514];
struct node{
	int x,t;
};
vector<node>a[514],b[511451];
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return x*f;
}
inline int ck(int x,int y){
	int ans=1e18;
	for(int i=0;i<b[x].size();i++){
		for(int j=0;j<b[y].size();j++){
			ans=min(ans,b[x][i].t+b[y][j].t+dis[b[x][i].x][b[y][j].x]);
		}
	}
	return ans;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		s[i]=read();
		for(int j=0;j<s[i];j++){
			a[i].push_back({read(),read()});
			b[a[i][j].x].push_back({i,a[i][j].t});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<b[i].size();j++){
			for(int k=j+1;k<b[i].size();k++){
				dis[b[i][j].x][b[i][k].x]=dis[b[i][k].x][b[i][j].x]=min(dis[b[i][j].x][b[i][k].x],b[i][j].t+b[i][k].t);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int x,y;q;q--){
		x=read();y=read();
		cout<<w[x]+w[y]+ck(x,y)<<'\n';
	}
	return 0;
}
/*
14:55~15:05 think
15:05~15:15 code
*/