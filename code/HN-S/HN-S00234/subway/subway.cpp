#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,w;
struct DF{
	int v;
};
vector<int> q[444440];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w;
		q[i].push_back({m+i,w});
		q[m+i].push_back({i+m,w});
	}
	for(int i=1;i<=q;i++){
		cin>>k;
		for(int j=1,l,r;j<=k;j++){
			cin>>l>>r;
			q[i].push_back({l,r});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		
	}
	return 0;
}
