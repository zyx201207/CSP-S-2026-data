#include<bits/stdc++.h>
using namespace std;
#define int long long 
typedef pair<int,int> pii;
struct node{
	int x;
	int val;
	node() {
		x=0; val=0;
	}
	node(int _x,int _val) {
		x=_x; val=_val;
	}
	bool operator<(const node &b)const{
		return val>b.val;
	}
}; 
priority_queue<node> q;
const int N=500005; 
int inf=1;
int G[505][505];
vector<pii> wwt[N],vec[N];
int opt,n,m,D,Q;
int ww[N];
int dst[505],vis[505];
int dwz[505][505];
int read() {
	char ch=getchar();
	while(!(ch>='0' && ch<='9')) {
		ch=getchar();
	}
	int ans=0;
	while(ch>='0' && ch<='9') {
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans;
}
void prnt(int x){
	if(x<=9) {
		putchar(x+'0');
		return ;
	}
	prnt(x/10);
	putchar(x%10+'0');
}
void dij(int st){
	for(int i=1;i<=n;i++) {
		dst[i]=inf;
		vis[i]=0;
	}
	dst[st]=0;
	while(!q.empty()) q.pop();
	q.push(node(st,0));
	while(!q.empty()){
		node A=q.top();
		q.pop();
		int x=A.x;
		if(vis[x]) continue;
		vis[x]=1;
		for(pii B:vec[x]) {
			int y=B.first;
			int z=B.second;
			if(dst[y]>dst[x]+z) {
				dst[y]=dst[x]+z;
				q.push(node(y,dst[y]));
			}
		}
	}
	for(int i=1;i<=n;i++) {
		dwz[st][i]=dst[i];
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	opt=read(); n=read(); m=read(); D=read();Q=read();
	for(int i=1;i<=m;i++) {
		ww[i]=read();
	}
	for(int i=1;i<=14;i++) inf=inf*10;
	for(int i=1;i<=n;i++) {
		int kk=read();
		for(int j=1;j<=kk;j++) {
			int x=read() , y=read();
			wwt[x].push_back(make_pair(y,i));
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			G[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++) {
		int sz=wwt[i].size();
		if(sz==1) continue;
		for(int j=0;j<sz;j++) {
			for(int k=j+1;k<sz;k++) {
				int x=wwt[i][j].second;
				int y=wwt[i][k].second;
				int z=wwt[i][j].first+wwt[i][k].first;
				G[x][y]=min(G[x][y],z);
				G[y][x]=min(G[y][x],z);
			}
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(i==j) continue;
			if(G[i][j]<inf) {
				vec[i].push_back(make_pair(j,G[i][j]));
			}
		} 
	}
	for(int i=1;i<=n;i++) {
		dij(i);
	}
	while(Q--) {
		int x=read(), y=read();
		int ans=inf;
		for(pii A:wwt[x]) {
			int st=A.second;
			for(pii B:wwt[y]) {
				int ed=B.second;
				int val=dwz[st][ed]+A.first+B.first;
				ans=min(ans,val);
			}
		}
		ans+=ww[x]+ww[y];
		prnt(ans);
		putchar('\n');
	}
	return 0;
}

