#include<bits/stdc++.h>
using namespace std;
typedef int i32;
typedef unsigned int u32;
typedef long long i64;
typedef unsigned long long u64;
typedef __int128 i128;
typedef float f32;
typedef double f64;
typedef long double f128;
#define endl '\n'
const i64 N=5e5+10;
i64 n,m,a[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(i64 i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(i64 r=n,l=n,sum=0;r>=1;r--){
		while(l>1&&sum+a[r]-a[l-1]<=m)l--,sum+=a[r]-a[l];
		ans=max(ans,r-l+1),sum-=(r-l+1)*(a[r]-a[r-1]);
	}
	cout<<ans;
	return 0;
}
