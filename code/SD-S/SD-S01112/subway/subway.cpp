#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0;
	int f=1;
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
const int N=520;
const int M=5e5+100;
int dis[N][N];
int W[M];
int c;
int n;
int m;
int q;
int cnt[M];
int id[M][21];
int T[M][21]; 
int d;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++)W[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int a=read();
			cnt[a]++;
			id[a][cnt[a]]=i;
			T[a][cnt[a]]=read();
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=1;k<=cnt[i];k++){
				int A=T[i][j]+T[i][k];
				dis[id[i][j]][id[i][k]]=min(dis[id[i][j]][id[i][k]],A);
				dis[id[i][k]][id[i][j]]=min(dis[id[i][k]][id[i][j]],A);
			}
		}
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
	while(q--){
		int x=read();
		int y=read();
		int ans=W[x]+W[y];
		int sum=LONG_LONG_MAX;
		for(int i=1;i<=cnt[x];i++){
			for(int j=1;j<=cnt[y];j++){
				int A=id[x][i];
				int B=id[y][j];
				sum=min(sum,dis[A][B]+T[x][i]+T[y][j]);
			}
		}
		cout<<ans+sum<<"\n";
	}
	return 0;
}
