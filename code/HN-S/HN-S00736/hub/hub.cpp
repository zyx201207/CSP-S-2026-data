#include <bits/stdc++.h>
#define int long long
#define ll long long
#define f(i,l,r) for(int i =l;i<=r;i++)
#define fe(i,l,r) for(int i = l;i>=r;i--)
#define endl '\n'

using namespace std;

const int N = 20;

int n,m;
vector<int> v[N];

int f[N];

int dfs(int x,int fa){
//	cout << x << endl;
	if(f[x])return 0;
	int mn = 1e12;
	for(auto xx : v[x])if(xx != fa){
		mn = min(mn,dfs(xx,x)+1);
	}
	return mn;
}

void dfsb(int x,int fa){
	f[x] = 0;
	for(auto xx : v[x])if(xx != fa && f[xx]){
		dfsb(xx,x);
	}
	return;
}

inline signed main1() {
	cin >> n >>m;
	f(i,1,n)v[i].clear();
	f(i,1,n-1){
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int mn = LLONG_MAX;
	f(i,0,(1<<n)-1){
		int sum = 0;
		f(j,0,n-1)f[j+1] = ((i>>j)&1),sum += f[j+1];
		if(sum >m)continue;
		int mx = 0;
		f(j,1,n)if(!f[j])mx = max(mx,dfs(j,0));
		sum = 0;
		f(j,1,n)if(f[j])dfsb(j,0),sum++;
		if(sum > 2)continue;
		
		mn = min(mn,mx);
//		if(mx == 1){
//			f(j,1,n)cout << f[j] << ' ';cout << endl;
//		}
	}
	cout << mn << endl;
	return 0;
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;cin >> T>>T;
	while(T--)main1();
	return 0;
}
/*

*/

