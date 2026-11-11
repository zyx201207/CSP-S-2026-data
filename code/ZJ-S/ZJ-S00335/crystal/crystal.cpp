// code by Umbrella.

// AC on 15:38

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back
#define mkp make_pair
namespace Umbrella{
	int n,m,a[500005];
	int prec[500005];
	void solve(){
		cin>>n>>m;
//		n=500000,m=100000000000000;
//		mt19937 rng(634793474);
		rep(i,1,n){
			cin>>a[i];
//			a[i]=rng()%11451419198+1;
		}
		sort(a+1,a+n+1,[](int u,int v){
			return u<v;
		});
		rep(i,1,n-1){
			int c=a[i+1]-a[i];
			prec[i]=prec[i-1]+c;
		}
		int l=1,sum=0,ans=0;
		rep(r,2,n){
			sum=sum+(r-l)*(a[r]-a[r-1]);
			while(sum>m){
				sum=sum-(prec[r-1]-prec[l]);
				l++;
			}
			ans=max(ans,r-l+1);
		}
		cout<<ans;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _T=1;
//	cin>>_T;
	while(_T--){
		Umbrella::solve();
	}
	return 0;
}