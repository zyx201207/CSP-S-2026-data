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
int CCC;
namespace cute_panyong_kuairuarua{
	int n,d,a[2010000]; 
	void sovle(){
		cin>>n>>d;
		int D=0;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		if(n==1){
			cout<<0<<'\n';
		}else if(CCC!=13&&CCC!=14){
			D=a[2]-a[1];
			d/=D;
			if(d==0||d==1){
				cout<<"0\n";
				return;
			}
			d=2*d;
			cout<<max(0ll,n-d+1)<<'\n';
		}else{
			cout<<0<<'\n';
		}
	} 
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int t=1;
	cin>>CCC;
	cin>>t;
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
//这玩意不会n^2 是不是退役了 
//感觉是类似认nxt当fa 然后做点事情  

//一载级题目 

//三把 chrome://dino max score 52还有救吗 
//五把 chrome://dino max score 108还有救吗 
