#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define pii pair<int,int>
#define fir first
#define sec second
const int N=5e5+7,inf=1e18;
inline int read(){
	int w=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') w=w*10+c-'0',c=getchar();
	return w*f;
} 
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0'); 
}
int n,m,d,q,tid,w[N];
struct node{
	int x,t;
};
int k[509];
vector<node> a[509];
int f[509][509];
vector<pii> tr[N];
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	tid=read();n=read(),m=read(),d=read(),q=read();
	rep(i,1,m) w[i]=read(); 
	rep(i,1,n){
		k[i]=read();
		a[i].resize(k[i]+1);
		rep(j,1,k[i]){
			a[i][j].x=read(),a[i][j].t=read();
			tr[a[i][j].x].push_back({i,a[i][j].t});
		}
	}
	rep(i,1,n){
		rep(j,1,n) f[i][j]=inf;
	}
	rep(i,1,n) f[i][i]=0;
	rep(i,1,n){
		rep(j,1,k[i]){
			int x=a[i][j].x,t=a[i][j].t;
			for(auto tmp:tr[x]){
				int y=tmp.fir,t2=tmp.sec;
				if(y==i) continue;
				f[i][y]=min(f[i][y],t+t2);
				f[y][i]=min(f[y][i],t+t2);
			}
		}
	}
	rep(k,1,n){
		rep(i,1,n){
			rep(j,i+1,n){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				f[j][i]=f[i][j];
			}
		}
	}
	rep(qid,1,q){
		int st=read(),ed=read();
		int res=inf;
		for(auto tmp1:tr[st]){
			int w1=tmp1.sec,u=tmp1.fir;
			for(auto tmp2:tr[ed]){
				int w2=tmp2.sec,v=tmp2.fir;
				res=min(f[u][v]+w1+w2,res);
			}
		}
		write(res+w[st]+w[ed]);
		puts("");
	}
	return 0;
}
