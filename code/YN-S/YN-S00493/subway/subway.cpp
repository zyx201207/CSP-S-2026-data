#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=6e2;
int c/*测试点数*/,n/*线路数*/,m/*站数*/,d/*最多经过线路数*/,q/*计划数*/;
pair<int,vector<pair<int,int>>>w[M];
pair<int,vector<pair<int,int>>>p[N];
pair<int,int>se;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i].first;
	}
	for(int i=1;i<=n;i++){
		cin>>p[i].first;
		for(int j=1;j<=p[i].first;j++){
			int st,t;
			cin>>st>>t;
			p[i].second.push_back(make_pair(st,t));
			w[p[i].first].second.push_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=q;i++){
		cin>>se.first>>se.second;
		cout<<w[se.first].first+w[se.first].second[0].second+w[se.second].first+w[se.second].second[0].second<<"\n";
	}
	return 0;
}
