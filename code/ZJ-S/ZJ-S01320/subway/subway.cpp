#include<bits/stdc++.h>
#define ll long long
#define INF 1e18
using namespace std;
ll read(){
	char c=getchar();
	ll l=1,ret=0;
	while(!isdigit(c))l=(c=='-'?-1:1),c=getchar();
	while(isdigit(c))ret=ret*10+c-'0',c=getchar();
	return ret*l;
}
void write(ll x){
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
const int N=507,M=5e5+7,Q=1e5+7;
ll c,n,m,d,q,w[M],k[N],ans[Q],dis[M<<1],T;
ll f[N][N];
struct abc{ll to,val;};
struct node{int n1,n2,id;}x[Q];
vector<abc> e[M<<1];
priority_queue<pair<ll,int>> qq;
pair<ll,int> now;
bool cmp(node n3,node n4){return n3.n1<n4.n1;}
void bfs(int s){
	qq.push(make_pair(0,s));
	dis[s]=0;
	ll fi,se;
	while(!qq.empty()){
		now=qq.top();
		qq.pop();
		fi=-now.first;
		se=now.second;
		if (fi>dis[se]) continue;
		for(abc ne:e[se]){
			if (fi+ne.val<dis[ne.to]){
				dis[ne.to]=fi+ne.val;
				qq.push(make_pair(-dis[ne.to],ne.to));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1,id;i<=n;i++){
		k[i]=read();
		id=i+m;
		int x,y;
		for(int j=1;j<=k[i];j++){
			x=read();y=read();
			e[x].push_back({id,y});
			e[id].push_back({x,y});
		}
		if (c>=12&&c<=19) T=y;
	}
	int q1,q2;
	for(int i=1;i<=q;i++){
		x[i].n1=read();x[i].n2=read();
		x[i].id=i;
		if (x[i].n1>x[i].n2) swap(x[i].n1,x[i].n2);
	}
	sort(x+1,x+1+q,cmp);
	if (c>=12&&c<=19){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=1e9;
			}
		}
		int num1,num2;
		for(int i=1;i<=m;i++){
			for(abc x:e[i]){
				for(abc y:e[i]){
					if (x.to==y.to) continue;
					num1=x.to-m,num2=y.to-m;
					f[num1][num2]=f[num2][num1]=2;
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		ll sum;
		for(int i=1;i<=q;i++){
			sum=INF;
			for(abc xx:e[x[i].n1]){
				for(abc yy:e[x[i].n2]){
					sum=min(sum,T*(f[xx.to-m][yy.to-m]+2));
				}
			}
			ans[x[i].id]=w[x[i].n1]+w[x[i].n2]+sum;
		}
		for(int i=1;i<=q;i++){
			write(ans[i]);
			putchar('\n');
		}
		return 0;
	}
	x[0].n1=0;
	for(int i=1;i<=q;i++){
		if (x[i].n1!=x[i-1].n1){
			for(int j=1;j<=m+n;j++)dis[j]=INF;
			bfs(x[i].n1);
		}
		ans[x[i].id]=w[x[i].n1]+w[x[i].n2]+dis[x[i].n2];
	}
	for(int i=1;i<=q;i++){
		write(ans[i]);
		putchar('\n');
	}
	return 0;
}