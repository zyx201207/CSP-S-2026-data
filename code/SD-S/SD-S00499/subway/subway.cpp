#include<bits/stdc++.h>
//#include <ext/rope>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
#define int long long
#define xxx const int mid=(l+r)>>1
using namespace std;
namespace cute_panyong_kuairuarua{
	vector<pair<int,int> >zt[501001];//可爱小正太 
	int n,m,d,q,w[501000],a[510][510];
	void sovle(){
		cin>>n;
		cin>>n>>m>>d>>q;
		for(int i=1;i<=m;++i){
			cin>>w[i];
		}
		for(int i=1;i<=n;++i){
			int k;
			cin>>k;
			for(int j=1;j<=k;++j){
				int a,t;
				cin>>a>>t;
				zt[a].push_back({i,t}); 
			}
			for(int j=1;j<=n;++j){
				if(i!=j){
					a[i][j]=1e18;
				}
			}
		}
		for(int i=1;i<=m;++i){
			for(auto x:zt[i])for(auto y:zt[i]){
				a[x.first][y.first]=min(x.second+y.second,a[x.first][y.first]); 
			} 
		} 
		for(int k=1;k<=n;++k){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
				}
			}
		}
		for(int i=1;i<=q;++i){
			int x,y;
			cin>>x>>y;
			int ans=1e18;
			for(auto U:zt[x])for(auto V:zt[y]){
				int u=U.first,v=V.first;
				ans=min(ans,a[u][v]+U.second+V.second);
			}
			cout<<ans+w[x]+w[y]<<'\n';
		}
	} 
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int t=1;
//	cin>>t;
	while(t--)cute_panyong_kuairuarua::sovle();
	return 0;
} 
//password: Oct31==Dec25?
//lg uid:27**21 (真忘了)
//demo,pynb
/*
@全体成员 象棋
I never die
对耶啊 
*/

/*

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


35
16
*/
// 0级题目 
