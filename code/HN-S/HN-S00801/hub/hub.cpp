#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t; 
vector<int> e[10001];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		cout<<k-1;
	}
	return 0;
}
