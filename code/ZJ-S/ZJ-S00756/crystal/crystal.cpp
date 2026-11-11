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
using namespace std;
bool beginmem;
#define N 500005
#define ll long long
namespace ElEp{
	ll n,m,a[N];
	void __init__(){
		return ;
	}
	void work(){
		cin>>n>>m;
		for(int i=1;i<=n;++i) cin>>a[i];
		sort(a+1,a+1+n);
		ll ans = 1,cur = 0,l = 1;
		for(int i=2;i<=n;++i){
			cur += (a[i]-a[i-1])*(i-l);
			while(cur>m){
				cur -= a[i]-a[l];
				++l;
			}
			ans = max(ans,i-l+1);
		}
		cout<<ans<<'\n';
		return ;
	}
}
bool endmem;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cout<<fixed<<setprecision(5);
	cerr<<fixed<<setprecision(5);
	int T = 1;
//	cin>>T;
//	begintim = clock();
	ElEp::__init__();
	while(T--) ElEp::work();
//	cerr<<"Time used: "<<(clock()-begintim)<<" ms.\n";
//	cerr<<"Memory used: "<<abs(&endmem-&beginmem)/1048576.<<" MB.\n";
	return 0;
}
/*
author: Ethereal_loss & Eternal_poem
created: 2026/10/31 14:35:15
exp: 100
先排序，然后然后我们分析以最后一个元素为基准水晶
我们最多能有多少颗能相同 
双指针维护 
TODO: 正确性检查，时间复杂度检查 
*/

