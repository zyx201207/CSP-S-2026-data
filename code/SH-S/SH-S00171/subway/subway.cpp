#include<iostream>
#include<vector>
using namespace std;
int w[500005],k[505],x[100005],y[100005];
struct node{
	int a,t;
};
vector<node>p[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	long long ans=0;
	for(int i=0;i<m;i++)cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			int u,v;
			cin>>u>>v;
			p[i].push_back({u,v});
		}
	}
	for(int i=0;i<q;i++){
		cin>>x[i]>>y[i];
		ans+=w[x[i]-1]+w[y[i]-1];
		ans+=p[x[i]-1][x[i]-1].t+p[x[i]-1][y[i]-1].t;
		cout<<ans<<endl;
	}
	return 0;
}
