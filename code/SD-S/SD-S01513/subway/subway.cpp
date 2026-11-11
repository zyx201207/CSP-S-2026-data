#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10;
int c,n,m,d,q;
int w[N],k[N];
int a[N][N];
int t[N][N];
int st[N];
vector<pair<int,int> >v[N];
int minn;
void dfs(int x,int y,int sum){
	if(x==y){
		minn=min(minn,sum);
		return ;
	}for(auto c:v[x]){
		int w=c.first,t=c.second;
		if(!st[w]){
			st[w]=1;
			dfs(w,y,sum+t);
			st[w]=0;
		}
	}
}int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			v[0].push_back({a[i][j],t[i][j]});
		}for(int j=1;j<=k[i];j++){
			for(int l=1;l<=k[i];l++){
				if(l!=j){
					v[a[i][l]].push_back({a[i][j],t[i][j]});
					v[a[i][j]].push_back({a[i][l],t[i][l]});
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		minn=INT_MAX;
		memset(st,0,sizeof(st));
		dfs(x,y,0);
		cout<<minn+w[x]+w[y]<<"\n";
	}return 0;
}
