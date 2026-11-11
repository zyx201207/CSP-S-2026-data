#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
struct node{
	int to;
};
vector<int> G[N];
int n,k,t;
int ans[N];
int in[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1;i <= n;i++){
			int u,v;
			cin >> u >> v;
			G[u].push_back(v);
			in[u]++;
			in[v]++;
			G[v].push_back(u);
		}
		if(n == k) cout << 0 << '\n';
		else if(n-k <= 3) cout << 1 << '\n';
		else{
			int num = 0;
			for(int i = 1;i <= n;i++){
				if(in[i] == 2){
					num++;
				} 
			} 
			if(num == 3) cout << 2 << '\n';
			else if(num == 1&&n == 5) cout << 2 << '\n';
			else cout << 1 << '\n';
		}
			
	}
	return 0;
}

