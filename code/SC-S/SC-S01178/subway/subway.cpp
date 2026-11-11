#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[1005];
vector<int> x[505];
vector<int> y[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int g,h;
			scanf("%d%d",&g,&h);
			x[i].push_back(g);
			y[i].push_back(h);
		}
	}
	while(q--){
		int rx,ry;
		cin>>rx>>ry;int sum=w[rx]+w[ry];
		for(int j=1;j<=n;j++){
			sum+=x[j][rx]+y[j][ry];
			
		}
		cout<<sum<<endl;
	}
	return 0;
}