#include<bits/stdc++.h>
using namespace std;
int a[50010],uu[50010],tt[50010],ans[5010][5010];
struct node{
	int u,t;
};
vector<node>maps[50010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>uu[j]>>tt[j];
		for(int j=1;j<=k;j++){
			for(int h=1;h<=k;h++){
				if(j==h)
					continue;
				maps[uu[j]].push_back((node){uu[h],tt[j]+tt[h]});
			}
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			if(i!=j)
				ans[i][j]=1e9;
	for(int i=1;i<=m;i++){
		queue<int>qu;
		qu.push(i);
		while(!qu.empty()){
			int now=qu.front();
			qu.pop();
			for(int j=0;j<maps[now].size();j++){
				node v=maps[now][j];
				int t2=ans[i][now]+v.t;
				if(t2<ans[i][v.u]){
					ans[i][v.u]=t2;
					qu.push(v.u);
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<ans[x][y]+a[x]+a[y]<<'\n';
	}
	return 0;
}
