#include<bits/stdc++.h>
#define maxn 1500005
#define inf 0x7f7f7f7f7f7f7f7f
using namespace std;

bool memjfs;
void read(long long &numx){
	register bool is_minus=0;
	register char xxx=getchar();
	numx=0;

	for(;xxx<'0'||xxx>'9';xxx=getchar()){
		if(xxx=='-'){
			is_minus=1;
		}
	}

	for(;xxx>='0'&&xxx<='9';xxx=getchar()){
		numx=(numx<<3)+(numx<<1)+(xxx^48);
	}

	if(is_minus){
		numx=-numx;
	}
}
struct data {
	long long next,val;
};
vector<data > a[maxn];
long long _,n,m,d,qus,ans;
bool vis[maxn];
long long l(long long level,long long num){
	return level*m+num;
}
struct node {
	long long v,dis;
};
queue<node > q;
void bfs(long long st,long long fin){
	memset(vis,false,sizeof(vis));
	q.push({st,0});
	ans=inf;
	
	long long last=0;
	while(!q.empty()){
		long long t=q.front().v;
		long long d=q.front().dis;
		q.pop();
		
		if(t==fin){
			ans=min(ans,d);
			continue;
		}
		
		if(t<2*m&&vis[t]){
			continue;
		}
		
		vis[t]=1;
		for(long long i=0;i<a[t].size();i++){
			if(a[t][i].next!=last){
				q.push({a[t][i].next,d+a[t][i].val});
			}
		}
		
		last=t;
	}
	
	printf("%lld\n",ans);
}
bool memjff;

int main(){
//	printf("%.8lfMB\n",(&memjff-&memjfs)/1024.0/1024.0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	read(_);read(n);read(m);read(d);read(qus);
	
	for(long long i=1,x;i<=m;i++){
		read(x);
		a[l(0,i)].push_back({l(1,i),x});
		a[l(1,i)].push_back({l(0,i),x});
	}
	
	for(long long i=1,k,x,t;i<=n;i++){
		read(k);
		
		for(long long j=1;j<=k;j++){
			read(x);read(t);
			a[l(1,x)].push_back({l(2,i),t});
			a[l(2,i)].push_back({l(1,x),t});
		}
	}
	
	for(long long i=1,s,f;i<=qus;i++){
		read(s);read(f);
		bfs(s,f);
	}
	return 0;
}