#include<bits/stdc++.h>
using namespace std;
int opt,T;
const int N=1005;
vector<int> vec[N];
int book[N];
int G[N][N];
int fa[N];
int n,k;
int dst[N][N];
int inf=5000;
int dan=5000;
int Find(int x){
	if(x==fa[x]) return x;
	return fa[x]=Find(fa[x]);
}
int read() {
	char ch=getchar();
	while((!(ch>='0' && ch<='9')) && ch!='-') {
		ch=getchar();
	}
	int FLAG=0;
	if(ch=='-'){
		FLAG=1;
		ch=getchar();
	}
	int ans=0;
	while(ch>='0' && ch<='9') {
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	if(FLAG){
		ans=-ans;
	}
	return ans;
} 
void floyd() {
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(G[i][k]==inf|| G[k][j]==inf) continue;
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
			}
		}
	}
}
void check() {
	int sum=0;
	for(int i=1;i<=n;i++) {
		sum+=book[i];
		fa[i]=i;
	}
	if(sum!=k) return ;
	for(int i=1;i<=n;i++) {
		for(int y:vec[i]){
			if(book[i] &&book[y]) {
				int fx=Find(i);
				int fy=Find(y);
				if(fx==fy) continue;
				fa[fx]=fy;
			}
			
		}
	}
	for(int i=1;i<=n;i++) {
		if(!book[i]) fa[i]=0;
		else fa[i]=Find(i);
	}
	sort(fa+1,fa+n+1);
	int len=unique(fa+1,fa+n+1)-(fa+1);
	
	if(fa[1]==0) len--;
//	cout<<len<<endl;
	if(len>2) return ;
	int mx=0;
	for(int i=1;i<=n;i++) {
		if(book[i]) continue;
		int kkk=inf;
		for(int j=1;j<=n;j++) {
			if(book[j]) {
				kkk=min(kkk,G[i][j]);
			}
		}
//		cout<<i<<" "<<kkk<<endl;
		mx=max(mx,kkk);
	}
	dan=min(dan,mx);
}
void dfs(int step) {
	if(step==n+1){
		check();
		return ;
	}
	book[step]=1;
	dfs(step+1);
	book[step]=0;
	dfs(step+1);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	opt=read();
	T=read();
	while(T--) {
		n=read(),k=read();
		dan=inf;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				G[i][j]=inf;
			}
		}
		for(int i=1;i<=n-1;i++) {
			vec[i].clear();
		}
		for(int i=1;i<=n-1;i++) {
			int x=read(),y=read();
			vec[x].push_back(y);
			vec[y].push_back(x); 
			G[x][y]=1;
			G[y][x]=1;
		}
		floyd();
		dfs(1);
		printf("%d\n",dan);
	}
	return 0;
}

