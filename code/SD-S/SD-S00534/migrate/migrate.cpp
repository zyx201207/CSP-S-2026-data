#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int a[N],L[N],R[N],lnum[N],rnum[N],qzh[N];
int n,d;

inline void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i){
		lnum[i]=rnum[i]=0;
	}
	for(int i=1;i<=n;++i) cin>>a[i];
	int r=1;
	for(int i=1;i<=n;++i){
		while(r<n&&a[r+1]-a[i]<=d) ++r;
		R[i]=r;
	}
	int l=n;
	for(int i=n;i>=1;--i){
		while(l>1&&a[i]-a[l-1]<=d) --l;
		L[i]=l;
	}
//	int ans=0;
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=n;++j) qzh[j]=0;
//		qzh[i]=1;
//		qzh[R[i]+1]--;
//		for(int j=1;j<=n;++j){
//			qzh[i]+=qzh[i-1];
//			if(!qzh[j]) continue ;
//			qzh[R[j]+1]-=qzh[i];
//			if(qzh[j]==2){
//				++ans;
//			}
//		}
//	}
//	cout<<ans<<'\n';
	L[n+1]=n+1;
//	for(int i=1 ;i<=n;++i) cout<<L[i]<<' '<<R[i]<<'\n';
	for(int i=1;i<=n;++i){
		if(R[i-1]<R[i]&&R[i]>i) lnum[R[i]]+=lnum[i];
		if(R[i]>i) lnum[R[i]]++;
	}
	for(int i=n;i>=1;--i){
		if(L[i+1]>L[i]&&L[i]<i){
			rnum[L[i]]+=rnum[i];
		}
		if(L[i]<i) rnum[L[i]]++;
	}
//	cout<<rnum[5]<<'\n';
	int ans=0;
//	cout<<'\n';
//	cout<<rnum[5]<<"QWQ"<<'\n';
	for(int i=1;i<n;++i){
//		cout<<lnum[i+1]<<' '<<rnum[i]<<'\n';
		if(L[i+1]==i) continue ;
		ans+=lnum[i+1]*rnum[i];
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int C,t=1;
	cin>>C>>t;
	while(t--){
		solve();
	} 
	return 0;
}
/*
1 1
10 3
0 1 2 3 4 5 6 7 8 9 10
*/

