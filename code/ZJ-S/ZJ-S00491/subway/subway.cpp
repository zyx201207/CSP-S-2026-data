#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e4+5;
int w[N];
int k[N];
int a[505][N];
int t[505][N];
int rk[N];
struct node{
	int x,y;
};
vector<node>e[N];
int c,n,m,d,q;
inline int Dij(int st,int ed){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	q.push({0,st*d});
//	cout<<st*d<<" ";
	int ans[N];
	for(int i=1;i<=m*d;i++)ans[i]=1e9;
	ans[st*d]=0;
//	cout<<ed*d<<" ";
//	cout<<ans[ed*d]<<" ";
	while(!q.empty()){
		auto top=q.top();
//		cout<<1<<" ";
		q.pop();
//		cout<<ans[ed*d]<<"  ";
		int x=top.first;
		int y=top.second;
//		cout<<x;
		for(auto i:e[y]){
//			cout<<"rp++";
			int v=i.x;
			int w=i.y;
//			cout<<v<<" "<<w<<"  ";
//			cout<<ans[v]<<" "<<w+x<<"  ";
			if(ans[v]>w+x){
//				cout<<"rp++";
				ans[v]=w+x;
				q.push({ans[v],v});
			}
		}
	}
	return ans[ed*d];
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	d++;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][j];
			e[(a[i][j]-1)*d+i].push_back({a[i][j]*d,t[i][j]});
			e[a[i][j]*d].push_back({(a[i][j]-1)*d+i,t[i][j]});
			for(int o=1;o<j;o++){
				e[(a[i][j]-1)*d+i].push_back({(a[i][o]-1)*d+i,0});
				e[(a[i][o]-1)*d+i].push_back({(a[i][j]-1)*d+i,0});
			}
		}
	}
//	for(auto i:e[40]){
//		cout<<i.x<<"rp++";
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
//		cout<<Dij(x,y)<<" ";
		cout<<Dij(x,y)+w[x]+w[y]<<"\n";
	}
	return 0;
}
/*

*/
