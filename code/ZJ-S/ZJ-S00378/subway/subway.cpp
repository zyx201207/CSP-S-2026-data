#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=505,maxm=500005,maxd=21;
int c,n,m,d,q,w[maxm],dis[maxn][maxn];
struct Node{int sub,dis;};
vector<Node> pos[maxm];
namespace dhcio{
	inline int read(){
		char ch=getchar();int ret=0,f=1;
		while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
		while(ch>='0'&&ch<='9') ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
		return ret*f;
	}
	inline void write(int x){
		if(x<0) x=-x,putchar('-');
		if(x>9) write(x/10);
		putchar('0'+x%10);
	}
}
using namespace dhcio;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,63,sizeof dis);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int S=1;S<=n;S++){
		int len=read();
		for(int i=1;i<=len;i++){
			int a=read(),t=read();
			pos[a].push_back((Node){S,t});
		}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		int len=pos[i].size();
		for(int j1=0;j1<len;j1++)
		for(int j2=0;j2<len;j2++){
			if(j1==j2) continue;
			dis[pos[i][j1].sub][pos[i][j2].sub]=min(dis[pos[i][j1].sub][pos[i][j2].sub],pos[i][j1].dis+pos[i][j2].dis);
		}
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++){
		int now=dis[i][k]+dis[k][j];
		if(now<dis[i][j]) dis[i][j]=dis[j][i]=now;
	}
	while(q--){
		int x=read(),y=read(),ans=dis[0][0];
		int lenx=pos[x].size(),leny=pos[y].size();
		for(int i=0;i<lenx;i++)
		for(int j=0;j<leny;j++)
		  ans=min(ans,dis[pos[x][i].sub][pos[y][j].sub]+pos[x][i].dis+pos[y][j].dis);
		write(ans+w[x]+w[y]);putchar('\n');
	}
	return 0;
}
