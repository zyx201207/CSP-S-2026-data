#include<bits/stdc++.h>
using namespace std;
#define int long long

int read(){
	int s=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*f;
} 

const int M=5e5+5;
const int N=505;
const int inf=1e18;

int n,m,q;
vector<pair<int,int> > e[M];
int f[N][N];
int wl[M];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(),n=read(),m=read(),read(),q=read();
	for(int i=1;i<=m;i++)wl[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int x=read(),w=read();
			e[x].push_back({i,w});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=inf;
	for(int i=1;i<=n;i++)f[i][i]=0;
			
	for(int i=1;i<=m;i++){
		for(int j=0;j<e[i].size();j++)
			for(int k=0;k<j;k++){
				int p1=e[i][j].first,w1=e[i][j].second;
				int p2=e[i][k].first,w2=e[i][k].second;
				f[p1][p2]=min(f[p1][p2],w1+w2);
				f[p2][p1]=min(f[p2][p1],w1+w2);
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int s=read(),t=read();
		int res=inf;
		for(int i=0;i<e[s].size();i++)
			for(int j=0;j<e[t].size();j++){
				int p1=e[s][i].first,w1=e[s][i].second;
				int p2=e[t][j].first,w2=e[t][j].second;
				res=min(res,w1+w2+f[p1][p2]);
			}
		printf("%lld\n",res+wl[s]+wl[t]);
	}
	
	return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/
