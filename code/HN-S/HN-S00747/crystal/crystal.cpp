#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans,s[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int l=0;
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
		while((i-l)*a[i]-(s[i]-s[l])>m)l++;
		ans=max(ans,i-l);
	}
	cout << ans;
	return 0;
}
/*
9 6
-10000 -1000 -100 -10 1 2 3 4 1000000
while(1) RP++;
*/

