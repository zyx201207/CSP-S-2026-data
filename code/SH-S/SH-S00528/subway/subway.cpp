#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],edg[505][505],k,a,t,x,y,temp;
vector<int> to[500005],tim[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
				if(i!=j) edg[i][j]=1000000000000000007;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> a >> t;
			for(int o=0;o<to[a].size();o++)
				edg[i][to[a][o]]=min(edg[i][to[a][o]],tim[a][o]+t);
			to[a].push_back(i);
			tim[a].push_back(t);
		}
	}
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
			edg[j][i]=edg[i][j];
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				edg[i][j]=min(edg[i][j],edg[i][k]+edg[j][k]);
				edg[j][i]=edg[i][j];
			}
	while(q--){
		cin >> x >> y;
		temp=1000000000000000007;
		for(int i=0;i<to[x].size();i++)
			for(int j=0;j<to[y].size();j++)
				temp=min(temp,tim[x][i]+tim[y][j]+edg[to[x][i]][to[y][j]]);
		cout << temp+w[x]+w[y] << '\n';
	}
	return 0;
}
