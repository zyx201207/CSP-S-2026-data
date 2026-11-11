#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<iomanip>
#include<vector>
#include<bitset>
#include<map>
#include<set>
#include<climits>
#include<cmath>
#include<random>
//#include<ctime>
using namespace std;
bool beginmem;
//clock_t begintim;
#define N 2000005
#define ll long long
namespace ElEp{
	ll n,d,a[N],R[N],RR[N];
	ll dp1[N],dp2[N],dp3[N];
	void __init__(){
		return ;
	}
	void work(){
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>a[i];
		for(int i = n,r = n;i;--i){
			while(a[r]-a[i]>d) --r;
			R[i] = r;
		}
		dp1[0] = dp2[0] = dp3[0] = 0;
		for(ll i=n;i;--i){
			dp1[i] = dp2[i] = dp3[i] = 0;
			if(R[i]-max(i,R[i-1])==0) RR[i] = 0;
			else if(R[i]-max(i,R[i-1])==1) RR[i] = RR[R[i]];
			else RR[i] = R[i];
		}
		for(ll i=n;i;--i){
			dp1[i] = (R[i]-max(i,R[i-1])>0?dp1[R[i]] + R[i] - max(i,R[i-1]):0ll);
		}
		for(ll i=n;i>2;--i){
			if(R[i]-max(i,R[i-1])==0) dp2[i] = (max(i,R[i-1])-max(i,R[i-2])>0?dp1[max(i,R[i-1])]:0ll) + max(i,R[i-1])-max(i,R[i-2]);
			else dp2[i] = dp2[RR[i]] + max(i,R[i-1])-max(i,R[i-2]);
		}
		ll ans = 0;
		for(ll i=n;i;--i){
			if(R[i]<=i) dp3[i] = 0;
			else if(R[i]==i+1) dp3[i] = dp3[i+1];
			else dp3[i] = dp2[R[i]];
			ans += dp3[i];
		}
//		for(int i=1;i<=n;++i) cout<<R[i]<<' ';
//		cout<<'\n';
//		for(int i=1;i<=n;++i) cout<<RR[i]<<' ';
//		cout<<'\n';
//		for(int i=1;i<=n;++i) cout<<dp2[i]<<' ';
//		cout<<'\n';
//		for(int i=1;i<=n;++i) cout<<dp3[i]<<' ';
//		cout<<'\n';
		cout<<ans<<'\n';
		return ;
	}
}
bool endmem;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cout<<fixed<<setprecision(5);
	cerr<<fixed<<setprecision(5);
	int T = 1,c;
	cin>>c>>T;
//	begintim = clock();
	ElEp::__init__();
	while(T--) ElEp::work();
//	cerr<<"Time used: "<<(clock()-begintim)<<" ms.\n";
//	cerr<<"Memory used: "<<abs(&endmem-&beginmem)/1048576.<<" MB.\n";
	return 0;
}
/*
author: Ethereal_loss & Eternal_poem
created: 2026/10/31 15:19:31
exp: 100
首先一定不会走回头路
那么有序dp就是有前途的
然后我们需要记录的有只有1条路径的点对数量和恰好有两条路径的点对数量
发现产生两条路径的构成只能是单次相邻交 
我们现在就需要尝试写出一个合理的check 
dpi表示i和i-1中间夹了多少个1 
先双指针求一下能到达的最远岛
然后考虑bfs的过程 
0 1
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000
c,调了2h+ 
*/

