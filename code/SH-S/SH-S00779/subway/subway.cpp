#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500010];
int vis[500010];
int vis1[510];
int k[500010];
int ti[510][20010];
long long dis[5010][5010];
struct node{
	int id;
	long long t;
	bool operator < (const node &a)const{
		return t>a.t;
	}
};
vector<node>g[500010];
vector<node> idx[510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int id;
			long long t;
			cin>>id>>t;
			ti[i][id]=t;
		}
	}
	for(int i=1;i<=n;i++){
	}
	return 0;
}
