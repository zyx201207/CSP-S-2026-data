#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q1,w[500010],a[500010],t[500010],k;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
vector<pair<int,int> >x[1010];
long long f[1010][1010]={0};
int main() {
   freopen("subway.in","r",stdin);
   freopen("subway.out","w",stdout);
  cin>>c>>n>>m>>d>>q1;
  for(int i=1;i<=m;i++){
  	cin>>w[i];
	}for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			if(j!=1){
				x[a[j]].push_back(make_pair(a[j-1],t[j]));
				x[a[j-1]].push_back(make_pair(a[j],t[j]));
			} 
		}
	}while(q1--){
		int xr,yr;
		memset(f,0x3f,sizeof(f));
		cin>>xr>>yr;
		f[xr][xr]=0;
		q.push(make_pair(0,xr));
		while(!q.empty()){
			int xx=q.top().second;
			q.pop();
			for(int i=0;i<x[xx].size();i++){
				int xxx=x[xx][i].first;
				if(f[xr][xxx]>=f[xr][xx]+x[xx][xxx].second){
					f[xr][xxx]=f[xr][xx]+x[xx][xxx].second;
					q.push(make_pair(f[xr][xxx],xxx));
				}
			}
		}cout<<f[xr][yr];
	}
  return 0;
}
