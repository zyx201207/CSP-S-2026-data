#include <bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define double long double
using namespace std;
const int N=5e5+5;
int n,m,a[N],c[N],d[N],ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) d[i]=d[i-1]+a[i];
	int l=1;
	for(int i=2;i<=n;i++){
		int sum=(i-l)*a[i]-d[i-1]+d[l-1];
		while(l<i&&sum>m){
			l++;
			sum=(i-l)*a[i]-d[i-1]+d[l-1];
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}


