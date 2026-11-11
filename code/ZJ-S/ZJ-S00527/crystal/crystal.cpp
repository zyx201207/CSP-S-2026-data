#include<bits/stdc++.h>
#define IOS cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define ll long long
#define db double 
#define pb push_back
#define eb emplace_back
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x,y) memset(x,y,sizeof(x))
#define PII pair<int,int>
#define lb(x) ((x)&(-x))
using namespace std;
const int N=5e5+20,M=1e5+20;
const ll INF=1e18,mod=998244353;
namespace H_H{
	int n;
	ll m,a[N],sum[N];
	bool check(int mid,int i){
		return m>=a[i]*mid-(sum[i]-sum[i-mid]);
	}
	int main(){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int l=0,r=i;
			while(l<r){
				int mid=(l+r+1)>>1;
				if(check(mid,i)) l=mid;
				else r=mid-1;
			}
			ans=max(ans,l);
		}
		cout<<ans<<"\n";
		return 0;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	IOS;H_H::main();
	// cerr<<(db)clock()/CLOCKS_PER_SEC<<"\n";
	return 0;
}
//g++ 1.cpp -o 1 -std=c++14 -O2 -Wall -Wextra -Wconversion -Wshadow "-Wl,--stack=1234567890"