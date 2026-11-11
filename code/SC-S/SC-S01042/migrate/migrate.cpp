#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int ret=0;bool opt=0;char in=getchar();
	while(!isdigit(in)){opt|=(in=='-');in=getchar();}
	while(isdigit(in)){ret=ret*10+(in^48);in=getchar();}
	return (opt?-ret:ret);
}
int lent,proc,knum,ret;
int dis[2000010];
int len[2000010];
inline int Abs(int x){return x<0?-x:x;}
class planA{//1~6
public:
	int dist[5010][5010];
	int ways[5010][5010];
	void run(){
		for(int i=1;i<=lent;i+=1){
			for(int j=1;j<=lent;j+=1){
				if(Abs(dis[j]-dis[i])<=knum){
					ways[i][j]=1;
					dist[i][j]=1;
				}else {
					ways[i][j]=0;
					dist[i][j]=lent+1;
				}
			}
		}for(int k=1;k<=lent;k+=1){
			for(int i=1;i<=lent;i+=1){
				if(i>=k)continue;
				if(dist[i][k]>lent)continue;
				if(ways[i][k]>4)continue;
				for(int j=1;j<=lent;j+=1){
					if(i>=j)continue;
					if(k>=j)continue;
					int ndis=dist[i][k]+dist[k][j];
					int nway=ways[i][k]*ways[k][j];
					if(dist[i][j]>ndis){
						dist[i][j]=ndis;
						ways[i][j]=0;
					}if(dist[i][j]==ndis){
						ways[i][j]+=nway;
					}
				}
			}
		}for(int i=1;i<=lent;i+=1){
			for(int j=i+1;j<=lent;j+=1){
				if(dist[i][j]>lent)continue;
				if(ways[i][j]==2)ret+=1;
			}
		}
	}
}A;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int test=read();proc=read();
	for(int t=1;t<=proc;t+=1){
		lent=read();knum=read();
		for(int i=1;i<=lent;i+=1){
			dis[i]=read();}ret=0;
		for(int i=1;i<lent;i+=1){
			len[i]=dis[i+1]-dis[i];
		}if(1<=test and test<=10)A.run();
		printf("%lld\n",ret);
	}return 0;
}