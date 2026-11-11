#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int c,n,m,d,q,w[maxn],k,x,y,a[505][505],dis;
vector<int> v[maxn];
map<pair<int,int>,int> mp;
int min(int a,int b){
	if(a<=b) return a;
	else return b;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(a,0x3f3f3f3f3f3f3f,sizeof(a));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>x>>y;
			v[x].push_back(i);
			mp[{x,i}]=y;
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=0;j<v[i].size();++j){
			for(int k=0;k<v[i].size();++k){
				if(k==j) continue ;
				a[v[i][j]][v[i][k]]=min(a[v[i][j]][v[i][k]],mp[{i,v[i][j]}]+mp[{i,v[i][k]}]);
				a[v[i][k]][v[i][j]]=a[v[i][j]][v[i][k]];
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			for(int k=j+1;k<=n;++k){
				a[i][k]=min(a[i][k],a[i][j]+a[j][k]);
				a[i][j]=min(a[i][j],a[i][j]+a[k][j]);
				a[k][j]=min(a[k][j],a[k][i]+a[i][j]);
				a[k][i]=a[i][k];
				a[j][i]=a[i][j];
				a[j][k]=a[k][j];
			}
		}
	}
	for(int i=1;i<=q;++i){
		cin>>x>>y;
		dis=0x3f3f3f3f3f3f3f;
		for(int j=0;j<v[x].size();++j){
			for(int k=0;k<v[y].size();++k){
//				cout<<dis<<' ';
				dis=min(dis,a[v[x][j]][v[y][k]]+mp[{x,v[x][j]}]+mp[{y,v[y][k]}]);
				if(v[x][j]==v[y][k]) dis=min(dis,mp[{x,v[x][j]}]+mp[{y,v[y][k]}]);
//				cout<<mp[{x,v[x][j]}]<<' '<<mp[{y,v[y][k]}]<<'\n';
			}
		}
		dis+=w[x]+w[y];
		cout<<dis<<'\n';
	}
	return 0;
}
