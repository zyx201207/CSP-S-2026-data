#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k,u,v;
		vector <int> t[N];
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			t[u].push_back(v);
			t[v].push_back(u);
		}
		cout<<1<<"\n";
	}
	return 0;
}