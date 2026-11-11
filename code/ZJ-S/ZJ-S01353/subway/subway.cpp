#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define R register
inline LL read(){
	LL x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void write(LL x){
	if(x<10){
		putchar(x+'0');
		return;
	}
	write(x/10);
	putchar(x%10+'0');
}
inline LL qsmin(LL x,LL y){
	if(x>y)return y;
	return x;
}
LL f[505][505],n,m,d,q,co[500005];
const LL inf=1e15;
struct Node{
	int x,y;
};
vector<Node>mp[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	n=read();n=read();m=read();d=read();q=read();
	for(R int i=1;i<=n;i++){
		for(R int j=1;j<=n;j++){
			f[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++)co[i]=read();
	for(R int i=1;i<=n;i++){
		int t=read(); 
		for(R int j=1;j<=t;j++){
			int u=read(),v=read();
			mp[u].push_back((Node){i,v});
		}
	}
	for(R int i=1;i<=m;i++){
		for(R int j=0;j<mp[i].size();j++){
			for(R int k=0;k<j;k++){
				Node a=mp[i][j],b=mp[i][k];
				f[a.x][b.x]=f[b.x][a.x]=qsmin(f[a.x][b.x],a.y+b.y);
			}
		}
	}
	for(R int i=1;i<=n;i++)f[i][i]=0;
	for(R int k=1;k<=n;k++){
		for(R int i=1;i<=n;i++){
			for(R int j=1;j<=n;j++){
				f[i][j]=f[j][i]=qsmin(f[i][k]+f[k][j],f[i][j]);
			}
		}
	}
	for(R int i=1;i<=q;i++){
		int a=read(),b=read();
		LL ans=inf;
		for(R int j=0;j<mp[a].size();j++){
			for(R int k=0;k<mp[b].size();k++){
				Node x=mp[a][j],y=mp[b][k];
				ans=qsmin(ans,f[x.x][y.x]+x.y+y.y);
			}
		}
		ans+=co[a]+co[b];
		write(ans);
		putchar('\n');
	}
	return 0;
}
