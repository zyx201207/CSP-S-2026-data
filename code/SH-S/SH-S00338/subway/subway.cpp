#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,M=1010;
ll n,mins,y,w[M],k[N],a[N][M],t[N][M],st[N][M];
bool book[N];
void dfs(int u,int x,ll s,int last){
	if(u==y){
		mins=min(mins,s+t[x][st[x][u]]);
		return;
	}
	for(int i=1;i<=n;i++){
		if(i!=x&&st[i][u]&&i!=last){
			dfs(u,i,s+t[x][st[x][u]]+t[i][st[i][u]],x);
		}
	}
	int ne;
	if(st[x][u]+1<=k[x]){
		ne=a[x][st[x][u]+1];
		if(!book[ne]){
			book[ne]=1;
			dfs(ne,x,s,last);
			book[ne]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll c,m,d,q,x;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			st[i][a[i][j]]=j;
		}
	}
	while(q--){
		cin>>x>>y;
		mins=1e18;
		for(int i=1;i<=n;i++){
			if(st[i][x]){
				book[x]=1;
				dfs(x,i,t[i][st[i][x]],0);
				book[x]=0;
			}
		}
		swap(x,y);
		for(int i=1;i<=n;i++){
			if(st[i][x]){
				book[x]=1;
				dfs(x,i,t[i][st[i][x]],0);
				book[x]=0;
			}
		}
		cout<<mins+w[x]+w[y]<<"\n";
	}
	return 0;
}

