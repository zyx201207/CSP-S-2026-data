#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pi pair<int,int>
#define mini pi,vector<pi>,greater<pi>
#define fs first
#define se second
#define P_Q priority_queue
using namespace std;
const int N = 2e6 + 5, inf = 0x3f3f3f3f3f3f3f3f;

int n, k;
int fa[N];
int siz[N];
int maxn[N];

int find(int x){
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}

vector<int> kk;
int ck = 0;
int ans = inf;


void solve(){
	int n;
	cin >> n;
	int x;
	cout << x % n << endl; 
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin); freopen("hub.out","w",stdout);

	int c, t;
	cin >> c >> t;
	while(t--) solve();

	return 0;
}

