#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
#define ull unsigned long long

int c,t;
int n,k;
vector<int> g[N]; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;cin>>>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
	}
	return 0;
}
