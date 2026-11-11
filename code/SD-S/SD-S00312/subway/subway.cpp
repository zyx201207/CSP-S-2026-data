#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using Pii=pair<int,int>;
using _i128=__int128;
using ull=unsigned long long;
const int maxN=500+10,maxK=5e5+10;
struct node{
	LL tm,id;
};
LL c,n,m,d,q;
LL w[maxK],k[maxN],a[maxN][maxK],t[maxN][maxK];
LL x[maxK],y[maxK];
LL fa[maxN][maxK];
vector<int> g[maxK];
bool vis[maxN][maxK];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) fa[i][j]=j;
	for(int i=1;i<=m;i++) cin>>w[i];
	bool flag=1;
	for(int i=1;i<=n,i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
	int ans=w[x[i]]+w[y[i]];
	cout<<ans;
	return 0;
}

