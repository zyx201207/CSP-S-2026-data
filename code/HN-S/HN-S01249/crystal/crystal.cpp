#include<bits/stdc++.h>
#define eps 1e-7
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
#define fi first
#define se second
#define MAXN 500005
int n;LL m,a[MAXN],s[MAXN];
bool check(int x){
	for(int i=x;i<=n;i++)
		if(a[i]*x-(s[i]-s[i-x])<=m)
			return 1;
	return 0;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n,mid,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
}
signed main(){
	auto ST=clock();
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1;//cin>>T;
	while(T--)solve();
	auto EN=clock();
	cerr<<LD(EN-ST)/CLOCKS_PER_SEC<<endl;

	return 0;
}