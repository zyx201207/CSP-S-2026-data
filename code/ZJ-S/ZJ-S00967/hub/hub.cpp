#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,k;
vector<int>g[N];
void ac(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout<<k/2<<endl;
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)ac();
	fclose(stdin);
	fclose(stdout);
	return 0;
}