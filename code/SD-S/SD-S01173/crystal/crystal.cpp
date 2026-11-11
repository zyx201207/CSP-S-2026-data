#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define pr pair<int,int>
#define mk(a,b) make_pair(a,b)
#define Tnow double(clock())/CLOCKS_PER_SEC
double TT=double(clock())/CLOCKS_PER_SEC;

const int N=5e5+5,inf=1e18;

int a[N],maxx=-inf,n,m,sum[N],l=1;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		while(l<=i&&((i-l+1)*a[i])-(sum[i]-sum[l-1])>m) l++;
		maxx=max(maxx,i-l+1);
	}
	cout<<maxx;
	return 0;
}
