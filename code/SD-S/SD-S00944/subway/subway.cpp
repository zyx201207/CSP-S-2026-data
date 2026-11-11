#include<cstdio>
#include<vector>
using namespace std;
const int maxn=510005;
long long chuzh1n[maxn];//w
int tunzh1n[maxn];
vector<int>zhand1an[maxn],jul1[maxn];
long long linj1e[505][505];
const long long infinfinfinf=4611686018427387904;//pow(2,62)
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&chuzh1n[i]);
	for(int i=1;i<=n;i++){
		int z;
		scanf("%d",&z);
		for(int j=1;j<=z;j++){
			int u,w;
			scanf("%d%d",&u,&w);
			tunzh1n[u]++;
			zhand1an[u].emplace_back(i);
			jul1[u].emplace_back(w);
		}
		for(int j=1;j<=n;j++)linj1e[i][j]=infinfinfinf;
	}
	for(int i=1;i<=n;i++)linj1e[i][i]=0; 
	for(int i=1;i<=m;i++){
		int z=tunzh1n[i];
		for(int j=1;j<z;j++){
			for(int k=0;k<j;k++){
				int d1an1=zhand1an[i][j];
				int d1an2=zhand1an[i][k];
				long long juli1=jul1[i][j]+jul1[i][k];
				linj1e[d1an1][d1an2]=linj1e[d1an2][d1an1]=min(linj1e[d1an1][d1an2],juli1);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			long long lj1k=linj1e[i][k];
			if(lj1k>>62)continue;
			for(int j=1;j<=n;j++)linj1e[i][j]=min(linj1e[i][j],lj1k+linj1e[k][j]);
//			printf("%d ",linj1e[i][j]);
		}
//		printf("\n");
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=infinfinfinf;
		int z1z1=tunzh1n[x];
		int z2z2=tunzh1n[y];
		for(int i=0;i<z1z1;i++){
			for(int j=0;j<z2z2;j++){
				ans=min(ans,linj1e[zhand1an[x][i]][zhand1an[y][j]]+jul1[x][i]+jul1[y][j]);
			}
		}
		printf("%lld\n",ans+chuzh1n[x]+chuzh1n[y]);
	}
	return 0;
}//Hallo,ween! Hello,Moni!
//To the STAR!!!
