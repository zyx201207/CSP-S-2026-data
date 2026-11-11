#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--) 
const int N=5009;
mt19937_64 rng(time(0));
int a[N];
signed main()
{
	freopen("migrate.in","w",stdout);
	cout<<0<<" "<<1<<"\n";
	cout<<300<<" "<<1000<<"\n";
	rep(i,1,300){
		a[i]=rng()%20000;
	}
	sort(a+1,a+301);
	rep(i,1,300) cout<<a[i]<<" ";
	cout<<"\n"; 
	return 0;
}
