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
	int n,a[501000],qzh[501000];
	int sum(int l,int r){
		return qzh[r]-qzh[l-1];
	}
	int calc(int l,int r){
		return a[l]*(r-l+1)-sum(l,r); 
	}
	void sovle(){
		int m;
		cin>>n>>m;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		reverse(a+1,a+n+1);	
		for(int i=1;i<=n;++i){
			qzh[i]=qzh[i-1]+a[i];
		}	
		int ans=0,r=0;
		for(int i=1;i<=n;++i){
			while(r<n&&calc(i,r+1)<=m){
				r++; 
			}
//			cerr<<r<<' ';
			ans=max(ans,r-i+1);
		}
		cout<<ans<<'\n';
	} 
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
//	freopen("crystal1.in","r",stdin);
//	freopen("crystal1.out","w",stdout);
//	freopen("crystal2.in","r",stdin);
//	freopen("crystal2.out","w",stdout);
//	freopen("crystal3.in","r",stdin);
//	freopen("crystal3.out","w",stdout);
//	freopen("crystal4.in","r",stdin);
//	freopen("crystal4.out","w",stdout);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
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
5 5
 1 2 4 8 9
 
 3
 
 5 8
 -3 -1 2 2 7
 
 4
*/
//-1级题目 
