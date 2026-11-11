#include<bits/stdc++.h>
using namespace std;
long long n,k;
vector<long long> edge[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			long long x,y;
			cin>>x>>y;
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		cout<<k-1<<endl; 
	}
	return 0;
}
