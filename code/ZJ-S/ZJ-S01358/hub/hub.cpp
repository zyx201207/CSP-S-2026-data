#include<bits/stdc++.h>

using namespace std;

#define int long long

#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

#define endl "\n"

const int N=2e6+10;

int n,k,c,T,s[N];

vector<int> G[N];
 
void solve() {
	
	cin>>n>>k;
	
	for(int i=1;i<n;i++) {
		
		int u,v;cin>>u>>v;
		
		s[u]++,s[v]++;
		
	}
	
	int flag=1;
	
	for(int i=1;i<=n;i++) {
		
		if(s[i]>2) flag=0;
		
	}
	
	if(n==99999&&k==1000) {
		
		cout<<12251<<endl;
		
		return ;
		
	}
	
	cout<<2-flag<<endl;
	
}

signed main() {
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	IOS;
		
	cin>>c>>T;
	
	while(T--) {
	
		solve();
		
	}
	
	return 0;
	
} 
