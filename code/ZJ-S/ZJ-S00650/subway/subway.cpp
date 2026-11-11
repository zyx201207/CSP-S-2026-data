#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int dis[505][505];
int l[505];
int a[505][505];
int b[505][505];
int pihua[500005];
int at[500005][21];
int ko[500005];
int cd[500005][21];
#ifdef __unix
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#else
#define getchar _getchar_nolock
#define putchar _putchar_nolock
#endif
int read(){
	int w=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-f;
		c=getchar();
	}
	while(isdigit(c)){
		w=(w<<3)+(w<<1)+(c^48);
		c=getchar();
	}
	return w*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
signed main(){
	#ifndef hyk0YF0Gamer
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	#endif
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)pihua[i]=read();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	dis[i][j]=100000000000000000ll;
	for(int i=1;i<=n;i++){
		l[i]=read();
		for(int j=1;j<=l[i];j++){
			a[i][j]=read();
			b[i][j]=read();
			int x=a[i][j];
			ko[x]++;
			at[x][ko[x]]=j;
			cd[x][ko[x]]=i;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)for(int j=1;j<ko[i];j++)
		for(int k=j+1;k<=ko[i];k++){
		int x=cd[i][j],y=cd[i][k];
		int X=at[i][j],Y=at[i][k];
		int mn=dis[x][y];
		mn=min(mn,b[x][X]+b[y][Y]);
		dis[x][y]=dis[y][x]=mn;
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y;
		x=read();y=read();
		int mn=200000000000000000ll;
		int ans=pihua[x]+pihua[y];
		for(int i=1;i<=ko[x];i++){
			for(int j=1;j<=ko[y];j++){
				int X=cd[x][i],Y=cd[y][j];
				mn=min(mn,b[X][at[x][i]]+
				b[Y][at[y][j]]+dis[X][Y]);
			}
		}
		ans=ans+mn;
		write(ans);
		putchar('\n');
	}
	return 0;
}
/*
ver 1:expected 80-100pts time 60min
time complexity O(n^3+m*d^2+q*d^2)
*/
