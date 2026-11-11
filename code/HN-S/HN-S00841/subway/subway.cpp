#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nd{
	bool il;
	int x,y;
	bool operator<(nd b)const{
		if(il==b.il){
			if(x==b.x){
				return y<b.y;
			}
			return x<b.x;
		}
		return il;
	}
};
int w[500005];
map<nd,vector<pair<nd,int> > >v;
map<nd,int>ans;
int k[505];
int x[100005],y[100005];
int a[505][100005],t[505][100005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		v[{0,i,0}].push_back({{0,i,1},w[i]});
		v[{0,i,1}].push_back({{0,i,0},w[i]});
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			v[{1,i,j}].push_back({{0,a[i][j],1},t[i][j]});
			v[{0,a[i][j],1}].push_back({{1,i,j},t[i][j]});
			if(j>=2){
				v[{1,i,j}].push_back({{1,i,j-1},0});
				v[{1,i,j-1}].push_back({{1,i,j},0});
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		queue<nd>q;
		q.push({0,x[i],0});
		ans.clear();
		ans[{0,x[i],0}]=0;
		while(q.size()){
			nd xx=q.front();
			q.pop();
			for(int j=0;j<v[xx].size();j++){
				if(ans.count(v[xx][j].first)){
					if(ans[xx]+v[xx][j].second>=ans[v[xx][j].first]){
						continue;
					}
				}
				ans[v[xx][j].first]=ans[xx]+v[xx][j].second;
				q.push({v[xx][j].first});
			}
		}
		cout<<ans[{0,y[i],0}]<<endl;
	}
	return 0;
}

