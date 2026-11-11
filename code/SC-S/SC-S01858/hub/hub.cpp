#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int c,T,n,k,fl[N],di[N],an;
struct A{int x,y;}e[N];
vector<int>g[N];
bool pd(){
	int cn=0;
	for(int i=1;i<n;i++){
		int x=e[i].x,y=e[i].y;
		if(fl[x]&&fl[y])cn++;
	}
	return k-cn<=2;
}
void ca(){
	queue<int>q;
	for(int i=1;i<=n;i++)di[i]=1e18;
	for(int i=1;i<=n;i++){
		if(fl[i])q.push(i),di[i]=0;
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:g[u]){
			if(di[v]>di[u]+1){
				di[v]=di[u]+1;
				q.push(v);
			}
		}
	}
}
void dfs(int x,int nu){
	if(x==n+1){
		if(nu!=k||!pd())return;
		ca();
		int no=0;
		for(int i=1;i<=n;i++)no=max(no,di[i]);
		an=min(an,no);
		return;
	}
	fl[x]=1,dfs(x+1,nu+1);
	fl[x]=0,dfs(x+1,nu);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k,an=1e18;
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
			e[i]={x,y};
		}
		dfs(1,0),cout<<an<<'\n';
	}
	return 0;
}