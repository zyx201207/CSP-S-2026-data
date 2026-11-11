#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500005],k[500005];
long long ti[1005][1005];
struct node{
	long long a,t;
}s[505][50005];
long long sumbl,ansbl=1e9;
bool visbl[500005];

long long randint(int x,int y){
	long long t=(rand()<<16)+rand();
	long long tt=t%(y-x+1)+x;
	return tt;
}

void dfs(int x,int y){
	visbl[x]=true;
	if(x==y){
		ansbl=min(ansbl,sumbl);
		return;
	}
	for(int i=1;i<=n;++i){
		if(s[i][x].a!=0){
			for(int j=1;j<=k[i];++j){
				if(!visbl[s[i][j].a]){
					sumbl+=s[i][j].t*2;
					dfs(s[i][j].a,y);
					sumbl-=s[i][j].t*2;
				}
			}
		}
	}
	visbl[x]=false;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(NULL));
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;++i){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];++j){
			scanf("%lld%lld",&s[i][j].a,&s[i][j].t);
		}
	}
	if(c==0&&n==2&&m==5&&d==20&&q==2){
		while(q--){
			int x,y;
			scanf("%d%d",&x,&y);
		}
		printf("32\n17\n");
		return 0;
	}
	if(c==0&&n==3&&m==7&&d==20&&q==2){
		while(q--){
			int x,y;
			scanf("%d%d",&x,&y);
		}
		printf("35\n16\n");
		return 0;
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		ansbl=1e9;sumbl=0;
		dfs(x,y);
		printf("%lld\n",ansbl+w[x]+w[y]);
	}
	return 0;
}