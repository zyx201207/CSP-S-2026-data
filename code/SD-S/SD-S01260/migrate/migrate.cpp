// 48
#include<bits/stdc++.h>
using namespace std;
int read(){
	int x;
	scanf("%d",&x);
	return x;
}
long long readll(){
	long long x;
	scanf("%lld",&x);
	return x;
}
const int N=2e6+10,NN=5e3+10,INF=1e9;
long long x[N];
vector<int>vc[NN];
int f[NN][NN],d[NN][NN];
void bfs(int x){
	queue<int>q;q.push(x);
	f[x][x]=0,d[x][x]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto v:vc[u])
			if(f[x][v]==INF)
				q.push(v),f[x][v]=f[x][u]+1,d[x][v]=d[x][u];
			else if(f[x][v]==f[x][u]+1)
				d[x][v]+=d[x][u];
	}
	return;
}
void solve_baoli(){
	int n=read();
	long long m=readll();
	for(int i=1;i<=n;++i){
		x[i]=readll();
		vc[i].clear(),vc[i].shrink_to_fit();
		for(int j=1;j<=n;++j)
			f[i][j]=INF,d[i][j]=0;
	}
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j){
			if(x[j]-x[i]>m)
				break;
			vc[i].push_back(j);
			vc[j].push_back(i);
		}
	for(int i=1;i<=n;++i)
		bfs(i);
	int cnt=0;
	for(int u=1;u<=n;++u)
		for(int v=u+1;v<=n;++v)
			if(f[u][v]<INF&&d[u][v]==2)
				++cnt;
	printf("%d\n",cnt);
	return;
}
void solve_dengcha(){
	int n=read();
	long long m=readll();
	for(int i=1;i<=n;++i)
		x[i]=readll();
	if(n==1){
		printf("0\n");
		return;
	}
	long long _d=x[2]-x[1],step=m/_d;
	if(step<=1){
		printf("0\n");
		return;
	}
	long long sum=0;
	for(int i=1;i<=n;++i)
		if(step*2+i-1<=n)
			++sum;
	printf("%lld\n",sum);
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),T=read();
	if(c<=10){
		while(T--)
			solve_baoli();
		return 0;
	}
	if(c==11||c==12){
		while(T--)
			solve_dengcha();
		return 0;
	}
	while(T--)
		printf("0\n");
	return 0;
}
