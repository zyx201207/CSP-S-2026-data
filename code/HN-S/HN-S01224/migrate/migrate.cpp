#include<bits/stdc++.h>
#include<bits/extc++.h>
#define mod 998244353
#define ll long long
#define hsh __gnu_pbds::gp_hash_table 
// 怎么感觉就是个贪心 + dp。 
// 2 hrs left.
// 是不是可以缩点。哎我在想什么。 
// 设 dp[i][j]=以 i 为起点到 j 的方案数。不对啊需要最短路。
// 手模一波样例。
//  1 2 3 4 d=2
//   1 1 1
//  1~4 显然有一对，并且有且仅有一对。
//  1 2 3 4 5 d=2
//   1 1 1 1
//  1~4 2~5 有两对。
// 所以 dis 至少要 > 3。 
// 不管了，先暴力。  
// 卧槽暴力写了我 1h，啥玩意啊。 
// 不管，get 24pts。 
using namespace std;
int csy,T; 
ll n;
ll d;
ll a[2000005];
__int128 b[2000005];
__int128 pr[2000005];
inline bool can_reach(int s,int t){
	// 考虑这个怎么快速求出来。
//	cout<<s<<' '<<t<<'\n';
	__int128 cnt=0,sum=0;
	vector<int> nodes; 
	nodes.push_back(s);
	for(int i=s+1;i<=t;i++){
		if(b[i]>d) return 0;
		cnt+=b[i];
		if(cnt>d){
			cnt=b[i];
			nodes.push_back(i-1); // 跳到这必须休息 
		}
//		cout<<(ll)cnt<<'\n';
	} 
	nodes.push_back(t); 
//	for(auto p:nodes) cout<<p<<' ';
//	cout<<'\n';
	// 现在已经有最短路的节点数了。
	// 我们直接枚举两个点。
	for(int i=1;i<nodes.size()-1;i++){ // 到了这个点，必须要跳 
		for(int j=1;nodes[i]-j>s;j++){
			int u=nodes[i]-j; // 前 j 个点 
			if(u<=nodes[i-1]) break;
//			cout<<"node "<<u<<'\n';
//			cout<<"prev "<<(ll)(pr[u]-pr[nodes[i-1]])<<" next "<<(ll)(pr[nodes[i+1]]-pr[u])<<'\n';
			if(pr[u]-pr[nodes[i-1]]<=d&&pr[nodes[i+1]]-pr[u]<=d){ // 可以从前面跳过来，也可以跳到后面 
				if(sum){
//					cout<<"sum enough\n";
					return 0;
				}
				sum++;
			}
		}
	}
//	if(!sum) cout<<"sum not enough\n";
	return sum==1;
}
inline void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]-a[i-1]; // distance from i-1 to i
	}
	b[1]=0; // no i-1
	for(int i=1;i<=n;i++) pr[i]=pr[i-1]+b[i]; // distance from 1 to i
//	for(int i=1;i<=n;i++) cout<<(unsigned ll)pr[i]<<' ';
//	cout<<'\n';
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+3;j<=n;j++){
			ans+=can_reach(i,j);
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>csy>>T;
	while(T--){
		solve();
	}
}
// Invisible Sorrow
