#include<bits/stdc++.h>
using namespace std;
long long c,n,m,dd,q,x,y,mi,sx,sy,fx,fy,l,flag,w[1000010],d[1000010],k[1000010],f[510][510];
vector <int> g[1000010];
struct no{
	long long a,t;
}qjj[510][10010];
bool cmp(no q,no h){
	return q.a<h.a;
}
void dfs(int fx,int x,int xx,long long s){
	if(s>d[x]) return ;
	d[x]=s;
	if(x==xx){
		mi=min(mi,s);return ;
	}
	for(int i=0;i<g[x].size();i++){
		int sx=g[x][i];
		if(sx==fx) continue;
		dfs(x,sx,xx,s+f[x][sx]);
	}
}
int sc(int x,int y){
	int t,w,mid;
	t=1,w=k[x];
	while(t<=w){
		mid=(t+w)/2;
		if(qjj[x][mid].a==y){
			return mid;
		}
		else if(qjj[x][mid].a<y){
			t=mid+1;
		}
		else if(qjj[x][mid].a>y){
			w=mid-1;
		}
	}
	return -1;
}
int ssc(int x,int y){
	for(int i=1;i<=k[x];i++){
		l=sc(y,qjj[x][i].a);
		if(l!=-1) return i;
	}
	return -1;
}
void check(){
	memset(f,127,sizeof f);
	for(int i=1;i<=n;i++){
		sort(qjj[i]+1,qjj[i]+1+k[i],cmp);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				l=-1;int k1=ssc(i,j);
				if(l!=-1){
					if(qjj[i][k1].a==qjj[j][l].a){
						f[i][j]=f[j][i]=min(f[i][j],qjj[i][k1].t+qjj[j][l].t);
						g[i].push_back(j);g[j].push_back(i);
					}	
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;mi=2e9;sx=sy=0;fx=fx=0;
		for(int j=1;j<=n;j++){
			int l=sc(j,x);
			if(l!=-1){
				flag=0;
				for(int z=1;z<=n;z++){
					int zj=sc(z,y);
					if(zj!=-1){
						if(j==z){
							mi=min(mi,w[x]+w[y]+qjj[j][l].t+qjj[z][zj].t);
						}
						else{
							for(int i=1;i<=n;i++) d[i]=2e18;
							dfs(0,j,z,w[x]+w[y]+qjj[j][l].t+qjj[z][zj].t);
						}
						flag=1;break;
					}
				}
			}
		}
		cout<<mi<<"\n";
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>qjj[i][j].a>>qjj[i][j].t;
		}
	}
	long long x=n*n*n*q;
	if(x<=1e8||(n==2)){check();return 0;}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/