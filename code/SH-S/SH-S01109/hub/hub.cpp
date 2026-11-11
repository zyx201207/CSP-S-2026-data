#include<bits/stdc++.h>

// expected: 15pts

using namespace std;

int c;
int floyd[20][20];
int per[20]; // for searching

int pre[20]; // for union-query set
int root(int x){
	return x = (pre[x] == x ? x : root(pre[x]));
}
void join(int x, int y){
	x = root(x), y = root(y);
	pre[y] = x;
}

bool Check(int n, vector<pair<int,int> > adj2){
	bool flag = 1;
	while(flag){
		flag = 0;
		for(auto x: adj2){
			if(per[x.first]&&per[x.second] && root(x.first) != root(x.second)){
				flag = 1;
				join(x.first,x.second);
			}
		}
	}
	for(int i = 1; i <= n; i ++){ // throw non-hub nodes
		pre[i] *= per[i];
	}
	int cnt = 0;
	for(int i = 1; i <= n; i ++){
		cnt += (pre[i]==i);
	}
//	if(cnt > 2){
//		for(int i = 1; i <= n; i ++) cout << per[i] << ' ';
//		cout << '\n';
//	}
//	for(int i = 1; i <= n; i ++) cout << per[i] << ' ';
//	cout << "-> ";
//	cout << cnt << '\n';
	return (cnt <= 2);
}

int solve(int n, int k){
	// init
	memset(per,0,sizeof per);
	memset(floyd,0x3f,sizeof floyd);
	for(int i = n; i+k-1 >= n; i --){
		per[i] = 1;
	}
	for(int i = 1; i <= n; i ++)
		pre[i] = i;
	//
	vector<pair<int,int> > adj2;
	vector<vector<int> > adj(20);
	for(int i = 1; i < n; i ++){
		int u,v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		adj2.push_back({u,v});
		floyd[u][v] = floyd[v][u] = 1;
	}
	for(int i = 1; i <= n; i ++)
		floyd[i][i] = 0;
	for(int k = 1; k <= n; k ++) for(int i = 1; i <= n; i ++) for(int j = 1; j <= n; j ++)
		floyd[i][j] = min(floyd[i][j],floyd[i][k]+floyd[k][j]);
	// floyd: correct
//	for(int i = 1; i <= n; i ++){
//		for(int j = 1; j <= n; j ++)
//			cout << floyd[i][j] << ' ';
//		cout << '\n';
//	}
	
	int ans = 0x0d000721; // watashino onani- wo mite kudasai!
	do{
		// first: Check if it is 2 blocks
		for(int i = 1; i <= n; i ++)
			pre[i] = i;
		if(!Check(n,adj2)) continue;
		// then, cal the cost
		int cost = -0x0d000721; // (negative) watashino onani- wo mite kudasai!
		for(int i = 1; i <= n; i ++){
			int cosinet = 0x0d000721; // I have a good coding style!
			for(int j = 1; j <= n; j ++){
				if(per[j]){
					cosinet = min(cosinet,floyd[i][j]);
				}
			}
			cost = max(cost,cosinet);
		}
		ans = min(ans,cost);
	} while(next_permutation(per+1,per+n+1));
	return ans;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int T; cin >> c >> T;
	while(T --){
		int n,k; cin >> n >> k;
		cout << solve(n,k) << '\n';
	}
	
	return 0;
}

/*
//freopen("hub.in","r",stdin);
//freopen("hub.out","w",stdout);
// freopen("hub.in","r",stdin);
// freopen("hub.out","w",stdout);
*/
