#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int c,n,m,d,q;
long long w[N];
int a[550][N];
long long t[550][N];
long long e[1010][1010];
void fuloyi(){
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
				e[j][i]=e[i][j];
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	bool fa=0;
	fa=1;
	memset(e,0x3f,sizeof(e));
	for(int i=1;i<=m;i++) e[i][i]=0;
	for(int i=1;i<=m;i++){
		scanf("%lld",w+i);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i][0]);
		for(int j=1;j<=a[i][0];j++){
			scanf("%d%lld",&a[i][j],&t[i][j]);
		}
		if(fa){
			e[a[i][1]][a[i][2]]=t[i][1]+t[i][2];
		}
	}
	fuloyi();
	while(q--){
		int s,t;
		scanf("%d%d",&s,&t);
		long long ans=e[s][t]+w[s]+w[t];
		printf("%lld\n",ans);
	}
	return 0;
} 

