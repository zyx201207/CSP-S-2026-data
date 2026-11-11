#include <bits/stdc++.h>
using namespace std;
void hub(){
	int n,k;
	cin>>n>>k;
	int u,v;
	vector<int> side[n+1];
	for(int i=1;i<n;i++){
		cin>>u>>v;
		side[u].push_back(v);
		side[v].push_back(u);
	}
	int maxx=1;
	for(int i=2;i<=n;i++){
		maxx=max(maxx,side[i].size());
	}
	if(k==1){
		cout<<1;
		return ;
	}
	else if(k==2){
		cout<<2;
		return ;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		hub();
	}
} 
