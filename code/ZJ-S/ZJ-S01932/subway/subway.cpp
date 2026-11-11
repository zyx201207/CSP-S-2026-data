#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e17;
const int M=5e5+10;
const int N=5e2+10;
const int D=2e1+10;
int c,n,m,d,q;
int w[M];
int cnt[M];
struct node{
	int li,ti;
}bel[M][D];
int dist[N][N];
inline int input(){
	int s=0,w=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') w=-w;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+ch-'0';
		ch=getchar();
	}
	return s*w;
}
inline int solve(int x,int y){
	int ans=inf;
	for(int i=1;i<=cnt[x];i++){
		for(int j=1;j<=cnt[y];j++){
			node ii=bel[x][i],jj=bel[y][j];
			ans=min(ans,dist[ii.li][jj.li]+jj.ti+ii.ti);
		}
	}
	return ans;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=input(),n=input(),m=input(),d=input(),q=input();
	for(int i=1;i<=m;i++) w[i]=input();
	for(int i=1;i<=n;i++){
		int k=input();
		for(int j=1;j<=k;j++){
			int a=input(),t=input();
			cnt[a]++;
			bel[a][cnt[a]].li=i;
			bel[a][cnt[a]].ti=t;
		}
		for(int j=1;j<=n;j++) dist[i][j]=inf;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=j;k<=cnt[i];k++){
				node jj=bel[i][j],kk=bel[i][k];
				if(j==k) dist[jj.li][kk.li]=0;
				else if(dist[jj.li][kk.li]>jj.ti+kk.ti)
					dist[jj.li][kk.li]=dist[kk.li][jj.li]=jj.ti+kk.ti;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dist[i][j]>dist[i][k]+dist[k][j])
				dist[i][j]=dist[j][i]=dist[i][k]+dist[k][j];
			}
		}
	}
	while(q--){
		int x=input(),y=input();
		cout<<w[x]+w[y]+solve(x,y)<<endl;
	}
	return 0;
}
