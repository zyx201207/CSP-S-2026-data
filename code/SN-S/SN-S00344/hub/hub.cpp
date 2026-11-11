// __       ___________________________________
// \ \     / /____  ____|  _______ \_____  ____|
//  \ \   / /    | |    | |______| |    | |
//   \ \ / /     | |    |         /     | |
//   /  ^ \      | |    |  ______ \     | |
//  / /  \ \     | |    | |______| |    | |
// /_/    \_\    |_|    |_________|     |_|
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define lowbit(x) (x & -x)
#define INF 0x3f3f3f3f3f3f3f3fll
#define inf 0x3f3f3f3f
#define FINF 0xcfcfcfcfcfcfcfcfll
#define finf 0xcfcfcfcf
using namespace std;
const int maxn=2e5+5;
const int maxm=1e6;
const int mod=998244353;
int n,m,t;
int ooo;
vector<int>vc[maxn];
int ans=INF;
// 唉，这把毁了
// 打不完了
// 吧唧菜的要死啊
// 555
// 救救孩子吧
// T2都不会555
// ll 
signed main()
{
	//哀兵必胜
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>ooo>>t;
while(t--){
	ans=INF;
	cin>>n>>m;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		vc[u].push_back(v);
		vc[v].push_back(u);
	}
	
}
	
	return 0;
}

