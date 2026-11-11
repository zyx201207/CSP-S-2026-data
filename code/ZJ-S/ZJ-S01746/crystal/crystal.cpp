#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3fll
#define For(i,l,r) for(int i=(l);i<=(r);++i)
#define Rof(i,l,r) for(int i=(l);i>=(r);--i)
namespace cjr2010{
	const int N=(int)(5e5+5);
	int n,m,a[N];
	void MAIN(){
		cin>>n>>m;
		For(i,1,n) cin>>a[i];
		sort(a+1,a+n+1);
		int l=1,sum=0,ans=1;
		For(r,2,n){
			sum+=(r-l)*(a[r]-a[r-1]);
			while(sum>m){
				sum-=a[r]-a[l];
				l++;
			}
			ans=max(ans,r-l+1);
		}
		cout<<ans<<"\n";
	}
}
signed main(){
	// freopen("crystal4.in","r",stdin);
	// freopen(".out","w",stdout);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);cjr2010::MAIN();
	return 0;
}
/*
g++ 1.cpp -o 1 -O2 -std=c++14 -static && .\1.exe
*/