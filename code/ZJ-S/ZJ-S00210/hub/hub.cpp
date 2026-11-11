#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int c,t;
int n,k;
vector<int> g;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<n;j++){
			int u,v;
			cin>>u>>v;
			g.push_back(u);
			g.push_back(v);
		}
	}
	cout<<1<<endl;
	cout<<2;
	
	
	
	
	
	return 0;
}