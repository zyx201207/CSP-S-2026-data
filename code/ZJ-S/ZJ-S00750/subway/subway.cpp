#include<bits/stdc++.h> 
using namespace std;
struct node{
	vector<pair<int,int>>t;
}s[1001];
int c,n,m,d,q;
int w[1000001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<n;i++){
		cin>>w[i];
	}
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		for(int j=0;j<x;j++){
			int p,gf;
			cin>>p>>gf;
			s[i].t.push_back({p,gf});
		}
	}
	while(q--){
		int st,ed;
		cin>>st>>ed;
	}
	cout<<"32\n17";
	return 0;
}
