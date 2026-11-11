#include<bits/stdc++.h>
#define ll long long
#define N 504
#define K 500005
using namespace std;
int c,n,m,d,q,w[N],k[N],a[N][K],t[N][K],fa[N];
void init(){
	for(int i=1;i<=N;i++)fa[i]=i;
}
int find(int x){
	return fa[x]==x?x:find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
vector<pair<int,int> >G[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k;j++){
			cin>>a[i][k]>>t[i][k];
			G[a[i][k]].push_back(make_pair(i,t[i][k]));
		}
	}
	for(int _=1;_<=q;_++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]<<endl;
		
	}
	return 0;
}
