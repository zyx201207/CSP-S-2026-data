#include <bits/stdc++.h>
#define int long long
#define ll long long
#define f(i,l,r) for(int i =l;i<=r;i++)
#define fe(i,l,r) for(int i = l;i>=r;i--)
#define endl '\n'

using namespace std;

const int N = 5e5 + 5;
const int M = 5e2 + 5;

int n,m;
int weight[N];
int c,d,Q;

int f[M][M];
int g[M];

vector<pair<int,int> > v[M];

//int go[M][N],wb[M][N],k[M];

vector<pair<int,int> > hav[N];

vector<pair<int,int> > go[M];
//int wb[M][N];

bitset<N> pan;

priority_queue<pair<int,int> > q;

inline void Dij(int y,int* f,int* g){
	f[y] = 0;
	q.push({-f[y],y});
//	f(i,1,m)cout << g[i] << ' ';cout<<endl;
	while(!q.empty()){
		int x = q.top().second;q.pop();
//		cout << x<<endl;
		if(g[x])continue;
		g[x] = 1;
		for(auto xx : v[x]){
			if(f[xx.first] > f[x] + xx.second){
				f[xx.first] = f[x] + xx.second;
				q.push({-f[xx.first],xx.first});
			}
		}
	}
}

signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//fc subway.out subway4.ans
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>c>>m>> n  >>d >>Q;
	f(i,1,n)cin >> weight[i];
	f(i,1,m){
		int ko;cin >> ko;
//		cout << i<< ' '<<ko <<endl;
		f(j,1,ko){
			int a,ki;
			cin >> a >> ki;
			go[i].push_back({a,ki});
			hav[a].push_back({i,ki});
		} 
		sort(go[i].begin(),go[i].end());
	}
//	cout << "SB\n";
	f(i,1,m)f(j,i+1,m){
//		cout << i << ' ' << j << endl;
		int pi = 0;int len = (ll)go[i].size()-1,ans = LLONG_MAX;
		f(l,0,len) {
			while(pi < go[j].size()-1 && go[j][pi].first < go[i][l].first)pi++;
//			cout << i << ' ' <<j << ' ' << pi << ' ' << l << ' ' << go[j][pi].first << ' ' << go[i][l].first<<endl;
			if(go[j][pi].first == go[i][l].first && go[j][pi].second + go[i][l].second <ans)ans = go[j][pi].second + go[i][l].second;
		}
		if(ans == LLONG_MAX)continue;
		v[i].push_back({j,ans});
		v[j].push_back({i,ans});
//		cout <<i << ' '<< j <<' '<<ans <<endl;
	}
//	cout << "SB\n";
	f(i,1,m)f(j,1,m)f[i][j] = 1e14;
	f(i,1,m){
		f(j,1,m)g[j] = 0;
		Dij(i,f[i],g);
//		cout << endl;
	} 
//	f(i,1,m){
//		f(j,1,m)cout << f[i][j] << ' ';cout << endl;
//	}
	
	f(i,1,Q){
		int x,y;
		cin >> x >> y;
		int ans = LLONG_MAX;
		f(j,0,(ll)hav[x].size() - 1)f(l,0,(ll)hav[y].size() - 1){
			int can = weight[x] + weight[y] + hav[x][j].second + hav[y][l].second + f[hav[x][j].first][hav[y][l].first];
			if(can < ans)ans = can;
		}
		cout << ans << endl;
	}

	return 0;
}
/*
int v[N];

int head[N],to[M],nxt[M];
int edgetot = 2;
void addedge(int a,int b,int c) {
	++edgetot;
	nxt[edgetot] = head[a];
	to[edgetot] = b;
}
*/

