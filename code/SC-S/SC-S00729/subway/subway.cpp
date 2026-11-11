#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
inline void read(int& x){
	int n=0,op=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') op=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		n=n*10+c-'0';
		c=getchar();
	}
	x=n*op;
}
struct node{
	int v,w;
};
bool operator<(node x,node y){
	return x.v<y.v;
}
vector<node>L[501],st[N];
long long dist[501][501];
int c,n,m,d,Q,T[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read(c),read(n),read(m),read(d),read(Q);
	for(register int i=1;i<=m;i++) read(T[i]);
	for(register int i=1;i<=n;i++){
		int k;
		read(k);
		L[i].resize(k);
		for(register int j=0;j<2*k;j++){
			if(j%2==0) read(L[i][j/2].v);
			else read(L[i][(j-1)/2].w);
		}
		sort(L[i].begin(),L[i].end());
		for(register int j=0;j<L[i].size();j++) st[L[i][j].v].push_back((node){i,L[i][j].w});
	}
	for(register int i=1;i<=n;i++){
		dist[i][i]=0;
		for(register int j=i+1;j<=n;j++){
			int l=0,r=0;
			dist[i][j]=2e18;
//			cout<<i<<","<<j<<":\n";
			while(l<L[i].size()&&r<L[j].size()){
				if(L[i][l].v==L[j][r].v){
//					cout<<L[i][l].v<<":"<<L[i][l].w+L[j][r].w<<"\n";
//					cout<<"("<<i<<":"<<l<<","<<j<<":"<<r<<")\n";
					dist[i][j]=min(dist[i][j],(long long)L[i][l].w+(long long)L[j][r].w),l++,r++;
				}
				else if(L[i][l].v<L[j][r].v) l++;
				else r++;
			}
			dist[j][i]=dist[i][j];
		}
	}
	for(register int k=1;k<=n;k++) for(register int i=1;i<=n;i++) for(register int j=1;j<=n;j++) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++) cout<<dist[i][j]<<" ";
//		cout<<"\n";
//	}
	while(Q--){
		int x,y;
		read(x),read(y);
		long long dt=2e18;
		for(register int i=0;i<st[x].size();i++){
			for(register int j=0;j<st[y].size();j++){
				int l=st[x][i].v,r=st[y][j].v;
//				cout<<l<<"->"<<r<<":"<<dist[l][r]<<"+"<<st[x][i].w<<"+"<<st[y][j].w<<"\n";
				dt=min(dt,dist[l][r]+(long long)st[x][i].w+(long long)st[y][j].w);
			}
		}
		dt=dt+(long long)T[x]+(long long)T[y];
		cout<<dt<<"\n";
	}
	return 0;
}