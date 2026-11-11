#include<bits/stdc++.h>
#define for1(i,x,y,k) for(int i=x;i<=y;i+=k)
#define for2(i,x,y,k) for(int i=x;i>=y;i-=k)
#define int long long
#define pb push_back
#define pf push_front
#define md (t[p].l+t[p].r>>1)
#define mi (lc+rc>>1)
#define mid (l+r>>1)
#define maotai mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define pii pair<int,int>
using namespace std;
const int N=2e6+5;
int c,t,n,d;
int x[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for1(i,1,n,1)
			cin>>x[i];
		int op=d/(x[2]-x[1]);
		if(n<=2 || op<=1){
			cout<<0<<'\n';
			continue;
		}
		int dx=op*2-1;
		cout<<max(0ll,n-dx)<<'\n';
	}
	return 0;
}
/*
0 1
5 3
1 2 3 4 5
*/
