#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#define re register
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
const int N=502,M=5e5+2,D=22;
int c,n,m,d,q,x,y,a[M],k,road[N][N],t[M][D],pos[M];
vector<int> id[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(re int i=1;i<=m;++i) a[i]=read();
	for(re int i=1;i<=n;++i){
		k=read();
		for(re int j=1;j<=k;++j){
			x=read(),y=read();
			t[x][pos[x]]=y;
			pos[x]++;
			id[x].push_back(i);
		}
	}
	memset(road,0x3f,sizeof road);
	for(re int i=1;i<=n;++i) road[i][i]=0;
	for(re int i=1;i<=m;++i){
		for(re int j=0;j<id[i].size();++j){
			for(re int g=j+1;g<id[i].size();++g){
				road[id[i][j]][id[i][g]]=min(road[id[i][j]][id[i][g]],t[i][j]+t[i][g]);
				road[id[i][g]][id[i][j]]=min(road[id[i][g]][id[i][j]],t[i][j]+t[i][g]);
			}
		}
	}
	for(re int g=1;g<=n;++g){
		for(re int i=1;i<=n;++i){
			if(road[i][g]>2e16) continue;
			for(re int j=1;j<=n;++j){
				if(road[g][j]>2e16) continue;
				road[i][j]=min(road[i][j],road[i][g]+road[g][j]);
			}
		}
	}
	while(q--){
		x=read(),y=read();
		int ans=a[x]+a[y],minn=2e16;
		for(re int i=0;i<id[x].size();++i){
			for(re int j=0;j<id[y].size();++j){
				minn=min(minn,road[id[x][i]][id[y][j]]+t[x][i]+t[y][j]);
			}
		}
		write(minn+ans);
		putchar('\n');
	}
	return 0;
}
