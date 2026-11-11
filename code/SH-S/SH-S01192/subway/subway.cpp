#include<cstdio>
#include<cstring>
using namespace std;
inline long long readin(){
	long long num=0;
	char ch=' ';
	long long sgn=1;
	while(ch==' '||ch=='\n'||ch=='\r')ch=getc(stdin);
	if(ch!=EOF)if(ch=='-')sgn=-1,ch=getc(stdin);
	while('0'<=ch&&ch<='9'&&ch!=EOF){
		num=((num<<1)+(num<<3))+((long long)ch-'0');
		ch=getc(stdin);
	}
	return num*sgn;
}
int E[500010],V[500010],nxt[500010],cnt=0;
long long wt[500010];
//solid
int sE[500010],sV[500010],Vmx[500010],scnt=0;
long long swt[500010];
long long dist[500010];
inline void addedge(int u,int v,long long w){
	nxt[++cnt]=V[u];
	V[u]=cnt;
	E[cnt]=v;
	wt[cnt]=w;
}
inline void saddedge(int u,int v,long long w){
	++scnt;
	if(!Vmx[u])Vmx[u]=scnt;
	sV[u]=scnt;
	sE[scnt]=v;
	swt[scnt]=w;
}
int C,N,M,D,Q;
long long dst[510][510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=0;i<=500;i++){
		for(int j=0;j<=500;j++)dst[i][j]=0xf3f3f3f3f3f3f; 
		dst[i][i]=0; 
		
	}
	C=readin(),N=readin(),M=readin(),D=readin(),Q=readin();
	for(int i=1;i<=M;i++)dist[i]=readin();
	for(int i=1;i<=N;i++){
		int K=readin(); 
		for(int j=1;j<=K;j++){
			int u=readin();
			long long w=readin();
			addedge(u,i,w);
		}
	}
	for(int i=1;i<=M;i++){
		for(int j=V[i];j;j=nxt[j]){
			saddedge(i,E[j],wt[j]);
		}
	}
	for(int i=1;i<=M;i++){
		for(int j=sV[i];j>=Vmx[i];j--){
			for(int k=sV[i];k>=Vmx[i];k--){
				dst[sE[j]][sE[k]]=(dst[sE[j]][sE[k]]>swt[j]+swt[k])?swt[j]+swt[k]:dst[sE[j]][sE[k]];
			}
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			for(int k=1;k<=N;k++){
				dst[j][i]=(dst[j][i]>dst[j][k]+dst[k][i])?dst[j][k]+dst[k][i]:dst[j][i];
			}
		}
	}
	for(int i=1;i<=Q;i++){
		int x=readin(),y=readin();
		if(x==y){
			puts("0");
			continue;
		}
		long long preans=0xf3f3f3f3f3f3f3f;
		for(int j=sV[x];j>=Vmx[x];j--){
			for(int k=sV[y];k>=Vmx[y];k--){
				preans=(dst[sE[j]][sE[k]]+swt[j]+swt[k]<=preans)?dst[sE[j]][sE[k]]+swt[j]+swt[k]:preans;
			}
		}
		printf("%lld\n",dist[x]+dist[y]+preans);
	}
	return 0;
}
