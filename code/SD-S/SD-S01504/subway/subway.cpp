#include<bits/stdc++.h>
using namespace std;
int n,m,a[20005][20005],d[500005],s,c[500][50005],t[500][50005],sumk,d2,q,f,w[500005];
//Oct31==Dec25?
vector<pair<int,int> >p[500005];
bool b[500005];
void dij(int s){
	for(int i=1;i<=m;i++){
		d[i]=2000000000;
		b[i]=0;
	}d[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	q.push({0,s});
	while(q.size()){
		auto x=q.top();
		q.pop();
		if(!b[x.second]){
			b[x.second]=1;
			for(auto y:p[x.second]){
				if(d[y.first]>d[x.second]+y.second){
					d[y.first]=d[x.second]+y.second;
					q.push({d[y.first],y.first});
				}
			}
		}
	}
}
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cin>>f>>n>>m>>d2>>q;
for(int i=1;i<=m;i++){
	cin>>w[i];
}
for(int i=1;i<=m;i++){
	for(int j=1;j<=m;j++){
		a[i][j]=2e9;
	}
}
for(int o=1;o<=n;o++){
	int k;
	cin>>k;
	sumk+=k;
	for(int j=1;j<=k;j++){
		cin>>c[o][j]>>t[o][j];
	}for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			if(i!=j){
				a[c[o][i]][c[o][j]]=min(a[c[o][i]][c[o][j]],t[o][i]+t[o][j]);
				a[c[o][j]][c[o][i]]=min(a[c[o][j]][c[o][i]],t[o][i]+t[o][j]);
			}
		}
	}
}for(int i=1;i<=m;i++){
	for(int j=1;j<=m;j++){
		if(a[i][j]!=2e9){
			p[i].push_back({j,a[i][j]});
		}
	}
}for(int i=1;i<=q;i++){
	int x,y;
	cin>>x>>y;
	dij(x);
	cout<<d[y]+w[x]+w[y]<<'\n';
}
	return 0;
}

