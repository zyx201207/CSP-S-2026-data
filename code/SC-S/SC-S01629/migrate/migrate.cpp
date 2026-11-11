#include<bits/stdc++.h>
#define N 2000002 
#define ll long long
using namespace std;
int c,t,n,ne[N],ls[N];
vector<int> A[N],B[N]; 
ll x[N],d,ans,dp[N],f[N];
inline void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1; i<=n; i++){
		A[i].clear();
		B[i].clear();
		f[i]=dp[i]=0;
		cin>>x[i];
	}
	for(int i=1; i<=n; i++){
		int L=i, R=n;
		while(L<R){
			int mid=(L+R+1)>>1;
			if(x[mid]-x[i]<=d) L=mid;
			else R=mid-1;
		} 
		ne[i]=L;
		if(L!=i) A[L].push_back(i);
	}
	for(int i=1; i<=n; i++){
		int L=1, R=i;
		while(L<R){
			int mid=(L+R)>>1;
			if(x[i]-x[mid]<=d) R=mid;
			else L=mid+1;
		} 
		ls[i]=L;
		if(L!=i) B[L].push_back(i);
	}
	// A[i]：哪些节点从左往右跳只能跳到，且只有一种方法跳到最多 i
	// B[i]：哪些节点从右往左跳只能跳到，且只有一种方法跳到最多 i 
	// dp[i]：一个元素左侧有多少个元素可以通过唯一的最优跳法到达该点 
	// f[i]：定义对称到“右侧”
	for(int i=1; i<=n; i++){
		if(A[i].size()==0) dp[i]=0;
		else dp[i]=A[i].size()+dp[A[i][0]];
	} 
	for(int i=n; i>=1; i--){
		if(B[i].size()==0) f[i]=0;
		else f[i]=B[i].size()+f[B[i].back()];
	}
	for(int i=1; i<=n; i++){
		if(i-ls[i]<=1) continue;
		ll jun=0;
//		if(ne[ls[i]]==i and ne[ls[i]+1]==i){
//			jun+=f[i]*(dp[ls[i]+1]-(ne[ls[i]]==ls[i]+1));
//		}
		jun+=(dp[ls[i]+1]-(ne[ls[i]]==ls[i]+1));
		ans+=jun;
	}
	cout<<ans<<"\n";
}
int main(){
//	system("fc migrate.out migrate4.ans");
//	return 0;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
} 

/*
0 1
5 2
1 2 3 4 5

*/