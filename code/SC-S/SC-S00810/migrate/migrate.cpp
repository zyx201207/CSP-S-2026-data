#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using pii = pair<int,int>;
#define inf 1e18
using ull = unsigned long long;
using lf = double;
const int MAXN = 2e6 + 5;

int c,T;
int n,d;
vector<pii>edge[MAXN]; 
int arr[MAXN];
queue<int>q;
ll in[MAXN],ans[MAXN];

void init() {
	for (int i=0;i<=n;i++) edge[i] = vector<pii>();
	for (int i=0;i<=n;i++) arr[i] = 0;
	q = queue<int>();
	for (int i=0;i<=n;i++) ans[i] = 1;
	ans[1] = 0;
	for (int i=0;i<=n;i++) in[i] = 0;
} 

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--) {
		init();
		cin>>n>>d;
		for (int i=1;i<=n;i++) {
			cin>>arr[i];
		}
		for (int i=1;i<=n;i++) {
			for (int j=i;j<=n;j++) {
				if (i != j && arr[j] - arr[i] <= d) {
					edge[i].push_back({j,abs(arr[j] - arr[i])});
					in[j]++;
				}
			}
		}
		for (int i=1;i<=n;i++) {
			if (in[i] == 0) q.push(i);
		}
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for (auto v : edge[u]) {
				ans[v.first] += ans[u];
				in[v.first]--;
				if (in[v.first] == 0) {
					q.push(v.first);
				}
			}
		}
		int cnt =0 ;
		for (int i=1;i<=n;i++) {
			if (ans[i] == 2) {
				cnt++;
			}
		}
		cout<<cnt<<endl;
	} 
	return 0;
}