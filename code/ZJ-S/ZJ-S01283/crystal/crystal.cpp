#include <bits/stdc++.h>
using namespace std;
namespace LUCKY{

using ll = long long;
#define int long long
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rof(i,a,b) for(int i=(a);i>=(b);--i)

constexpr int N=5e5+5;

int n,a[N],m;
int Sum[N];

int Get(int l,int r){
	return a[r]*(r-l+1)-(Sum[r]-Sum[l-1]);
}

void OvO(){
	cin>>n>>m;
	For(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);
	For(i,1,n) Sum[i]=Sum[i-1]+a[i];

	// cerr<<n<<' '<<m<<endl;
	// cerr<<"a: ";
	// For(i,1,n) cerr<<a[i]<<' ';; cerr<<endl;
	// cerr<<"Sum: ";
	// For(i,1,n) cerr<<Sum[i]<<' ';; cerr<<endl;

	int ans=0;
	For(i,1,n){
		int l=1,r=i,res=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(Get(mid,i)>m) l=mid+1;
			else r=mid-1,res=mid;
		}
		// cerr<<i<<' '<<res<<endl;
		ans=max(ans,i-res+1);
	} cout<<ans<<endl;
}

#undef int
} using LUCKY::OvO;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	OvO(); return 0;
}

/*

g++ crystal.cpp -o crystal -std=c++14 -O2 -Wall -Wextra -static

6 12
-1 -3 5 4 2 1

*/