#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
inline int read(){
   int s=0,w=1;char ch=getchar();
   while(!isdigit(ch)){if(ch=='-'){w=-1;}ch=getchar();}
   while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int c,n,m,d,q,a,x,y;
int w[500010],k,t[510][500010];
long long dis[510][510],ans;
vector<int> trans[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f3f3f3f3f3f3f3f,sizeof(dis));
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		k=read();
		for(int j=0;j<k;j++){
			a=read();
			t[i][a]=read();
			for(int g=0;g<trans[a].size();g++){
				int v=trans[a][g];
				dis[v][i]=min(dis[v][i],(long long)t[v][a]+t[i][a]);
				dis[i][v]=dis[v][i];
			}
			trans[a].push_back(i);
		}
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int g=1;g<=n;g++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][g]+dis[g][j]);
				dis[j][i]=dis[i][j];
			}
		}
	}
	for(int g=0;g<q;g++){
		x=read(),y=read();
		ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<trans[x].size();i++){
			for(int j=0;j<trans[y].size();j++){
				int u=trans[x][i],v=trans[y][j];
//				printf("%d %d %d %d %d %d %d\n",u,v,dis[u][v],w[x],w[y],t[u][x],t[v][y]);
				ans=min(ans,dis[u][v]+w[x]+w[y]+t[u][x]+t[v][y]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
