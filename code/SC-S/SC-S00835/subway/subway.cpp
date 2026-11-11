#include<bits/stdc++.h>
using namespace std;
int c,n,m,r,q,w,b[500005],t[500005],e,d[500005],x,y;
vector<pair<int,int>>edge[11000];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q1;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>r>>q;
	for(int i=1;i<=m;i++){
		cin>>w;
		edge[i*22].push_back({i*22+1,w});
		edge[i*22+1].push_back({i*22,w});
//		a[i*22][i*22+1]=w;a[i*22+1][i*22]=w;
	}
//	for(int i=1;i<=10500;i++){
//		for(int j=1;j<=10500;j++)
//		a[i][j]=1e9;
//	}
	for(int i=1;i<=n;i++){
		cin>>e;
		for(int j=1;j<=e;j++){
			cin>>b[j]>>t[j];
			edge[b[j]*22+1+i].push_back({b[j]*22+1,t[j]});
			edge[b[j]*22+1].push_back({b[j]*22+1+i,t[j]});
//			a[b[j]*22+1+i][b[j]*22+1]=t[j];a[b[j]*22+1][b[j]*22+1+i]=t[j];
		}
		for(int j=2;j<=e;j++){
			edge[b[j]*22+1+i].push_back({b[j-1]*22+1+i,0});
			edge[b[j-1]*22+1+i].push_back({b[j]*22+1+i,0});
//			a[b[j-1]*22+1+i][b[j]*22+1+i]=0;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		for(int i=1;i<=m;i++){
			d[i]=-1e9;
		}
		d[x]=x*22;
		q1.push({d[x],0});
		while(q1.size()){
			int s=q1.top().first,s1=q1.top().second;
			q1.pop();
			for(auto i:edge[s]){
				if(i.first+d[i.first]>=d[i.second]){
					d[i.second]=i.first+d[i.first];
//					cout<<i.first+d[i.first]<<' '<<d[i.second]<<' ';
					q1.push({d[i.second],i.first});
				}
			}
		}
		cout<<d[y]<<'\n';
	} 
	return 0;
}