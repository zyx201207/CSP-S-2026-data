#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;

int C,T;
int n;
ll d,x[N];

inline void solve1(){
	ll a=d/(x[2]-x[1]);
	if(a<=1){
		printf("0\n");
		return;
	}
	int res=0;
	for(int i=1;i<=n;++i){
		if(a*2-1+i<=n)++res;
		else break;
	}
	printf("%d\n",res);
	return;
}

inline void solve2(){
	if(n<=3){
		printf("0\n");
		return;
	}
	ll res=0;
	for(int i=2;i<=n-2;++i){
		int a = upper_bound(x+i+2, x+n+1, x[i-1]+d) - x;
		int b = upper_bound(x+i+2, x+n+1, x[i]+d) - x;
		int c = lower_bound(x+1, x+i, x[i+1]-d) - x;
		int e = lower_bound(x+1, x+i, x[i+2]-d) - x;
		res += 1ll*(b-a)*(e-c);
	}
	printf("%lld\n",res);
	return;
}

int tot,head[5005],to[15000005],nxt[15000005];
int dis[5005],f[5005];
queue<int> q;
inline void adde(int u,int v){
	++tot;
	to[tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
}
inline void solve3(){
	memset(head,0,sizeof head);
	tot=0;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(x[j]-x[i]<=d) adde(i,j);
			else break;
		}
	}
	int res=0;
	for(int i=1;i<=n;++i){
		memset(dis,0x3f,sizeof dis);
		memset(f,0,sizeof f);
		q.push(i);
		dis[i]=0, f[i]=1;
		while(q.size()){
			int u=q.front(); q.pop();
			for(int j=head[u];j;j=nxt[j]){
				int v=to[j];
				if(dis[u]+1<dis[v]){
					dis[v]=dis[u]+1;
					f[v]=f[u];
					q.push(v);
				}
				else if(dis[u]+1==dis[v]){
					f[v]+=f[u];
					if(f[v]>2)f[v]=3;
				}
			}
		}
		for(int j=1;j<=n;++j){
			if(f[j]==2) ++res;
		}
	}
	printf("%d\n",res);
	return;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	scanf("%d%d",&C,&T);
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;++i){
			scanf("%lld",x+i);
		}
		if(n==1){
			printf("0\n");
			continue;
		}
		if(C==11||C==12)solve1();
		else if(C==13||C==14)solve2();
		else solve3();
	}
	
	return 0;
}
