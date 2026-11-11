# include <bits/stdc++.h>
# define int long long
# define endl "\n"
//# define debug
using namespace std;

namespace in{
	const int BS = 1 << 20;
	char buffer[BS], *p1 = nullptr, *p2 = nullptr;
	
	inline char gc(){
		if(p1 == p2){
			p1 = buffer;
			p2 = p1 + fread(buffer, 1, BS, stdin);
			if(p1 == p2){
//				cout << "en\n";
				return EOF;
			}
		}
		
		return *(p1++);
	}
	
	inline int read(){
//# ifndef debug
//		int num = 0;
//		bool neg = false;
//		char ch = gc();
//		
//		while(!ch){
//			ch = gc();
//		}
//
//		while('0' <= ch && ch <= '9'){
//			num *= 10;
//			num += ch - '0';
//			ch = gc();
//		}
//
//		if(neg) return -num;
//		return num;
//# endif
//
//# ifdef debug
		int x;
		cin >> x;
		return x;
//# endif
	}
	
	inline void input(int &x){
		x = read();
		return ;
	}
}

using in::read;
using in::input;

const int N = 500 * 2 + 10;
const int M = 5e5 * 2 + 10;
const int INF = 1e16;

int w[M];
vector<int> a[N];
vector<int> t[N];

struct Node{
	int to, w;
};
vector<Node> e[N];

bool vis[N];
int step[N];

struct sNode{
	int x;
	bool operator < (const sNode &oth) const {
		return step[x] > step[oth.x];
	}
};

int c, n, m, d, q;

int dj(int st, int end){
# ifdef debug
		cout << "search for " << st << " to " << end << endl;
# endif

	priority_queue<sNode> sq;
	for(int i=1;i<=n+m;i++){
		vis[i] = false;
		step[i] = INF;
	}

	sq.push({st});
	vis[st] = true;
	step[st] = 0;
	
	while(!sq.empty()){
		int cur = sq.top().x; sq.pop();
# ifdef debug
		cout << "--- cur node is " << cur << " ---" << endl;
# endif

		for(auto it: e[cur]){
			int to = it.to, w = it.w;
# ifdef debug
			cout << "target node " << to << " step is " << step[to] << endl;
# endif	
			step[to] = min(step[to], step[cur] + w);

# ifdef debug
		cout << "from node " << cur << "(" << step[cur] << ") to node " << to << " with w=" << w << endl;
		cout << "node " << to << " step is " << step[to] << endl;
# endif

			if(!vis[to]){
				sq.push({to});
				vis[to] = true;
			}
		}
	}

# ifdef debug
		cout << "end earch for " << st << " to " << end << endl;
		cout << "the ans is " << step[end] << endl;
		cout << "===\n";
# endif

	return step[end];
}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input(c); input(n); input(m); input(d); input(q);
	
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	
	for(int i=1;i<=n;i++){
		int ki = read();
		for(int j=1;j<=ki;j++){
			int x;
			a[i].push_back(x = read());
			t[i].push_back(read());
//			master[x] = i;
		}
	}

//# ifdef debug
//	cout << "the arr master is like: \n";
//	for(int i=1;i<=m;i++){
//		
//	}
//	cout << "===\n";
//# endif

# ifdef debug
	cout << "the arr a is like: \n";
	for(int i=1;i<=n;i++){
		for(auto it: a[i]){
			cout << it << " ";
		}
		cout << endl;
	}
	cout << "===\n";
# endif

# ifdef debug
	cout << "the arr t is like: \n";
	for(int i=1;i<=n;i++){
		for(auto it: t[i]){
			cout << it << " ";
		}
		cout << endl;
	}
	cout << "===\n";
# endif
	
	// 线路节点编号 1 ~ n 
	// 站厅节点编号 n+1 ~ n+n
	// 将每个站台所在线路节点连接至站厅
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].size();j++){
			// link
			int u=i, v=a[i][j]+n;
			e[u].push_back({v, t[i][j]});
			e[v].push_back({u, t[i][j]});
		}
	}
	
# ifdef debug
	cout << "the map is like: \n";
	for(int i=1;i<=n;i++){
		for(auto it: e[i]){
			cout << "node " << i << " to node " << it.to << " with w=" << it.w << endl;
		}
	}
	cout << "===\n";
# endif

	for(int i=1;i<=q;i++){
		int x = read(), y = read();
		// 计算站厅间的距离 
		cout << dj(x+n, y+n)+w[x]+w[y] << endl;
	}
	
	return 0;
}
