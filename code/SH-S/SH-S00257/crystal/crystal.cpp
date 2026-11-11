#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(auto i=(l);i<=(r);i++)
#define irep(i,l,r) for(auto i=(l);i>=(r);i--)
#define sc cerr
#define qlog(x) {sc<<#x<<"="<<(x)<<"\n";}
#define qloga(a,l,r) {sc<<#a<<": "; rep(I,l,r){sc<<a[i]<<" ";} sc<<"\n";}
#define qlogSTL(a) {sc<<#a<<": "; for(const auto &x:a){sc<<x<<" ";} sc<<"\n";}
typedef long long ll;
typedef __int128 i128;

constexpr int N=1e6+10;
ll n,m,a[N],b[N];

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	rep(i,1,n)cin>>a[i];
	sort(a+1,a+1+n);

	rep(i,1,n)b[i]=b[i-1]+a[i];

	int ans=0;
	int j=1;
	rep(i,1,n){
		while(j<i && a[i]*(i-j+1)-(b[i]-b[j-1])>m)j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
}
