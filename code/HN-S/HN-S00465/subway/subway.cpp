#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
const int M=5e5+5;
const int N=505;
int c,n,m,d,q;
int w[M];
struct node{
	int y,w;
};
vector<node> g[N+M];
ll dp[N][N];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j]=(i==j?0:inf);
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		ll k;
		k=read();
		for(int j=1;j<=k;j++){
			int a,t;
			a=read(),t=read();
			node x1,x2;
			x1.y=m+i,x1.w=t;
			x2.y=a,x2.w=t;
			g[a].push_back(x1);
			g[m+i].push_back(x2);
		}
    }
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			node n1=g[i][j];
			ll y1=n1.y-m,w1=n1.w;
			for(int k=0;k<g[i].size();k++){
				node n2=g[i][k];
				ll y2=n2.y-m,w2=n2.w;
				dp[y1][y2]=min(dp[y1][y2],w1+w2);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	for(int i=1;i<=q;i++){
		int x,y;
		x=read(),y=read();
		ll ans=inf;
		for(int j=0;j<g[x].size();j++){
			ll xx=g[x][j].y-m,w1=g[x][j].w;
			for(int k=0;k<g[y].size();k++){
				ll yy=g[y][k].y-m,w2=g[y][k].w;
				ans=min(ans,w1+w2+dp[xx][yy]);
			}
		}
		write(ans+w[x]+w[y]);
		putchar('\n');
	}
	return 0;
} 
