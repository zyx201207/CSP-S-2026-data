#include <bits/stdc++.h>
using namespace std;
vector <int> tree[1000100];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	int n,m;
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			tree[x].push_back(y);
		}
		cout<<n-1-m/2<<endl;
	}
	return 0;
}
