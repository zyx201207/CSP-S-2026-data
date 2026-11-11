#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 500005;
ll n,m,a[MAXN];
ll pre[MAXN];
ll l,r,i,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(ll t=0;t<n;t++){
		cin >> a[t];
	}
	sort(a,a+n);
	l = 0;r = n-1;ans=0;
	while(l<r){i = (l+r)/2+1;
		pre[i] = 0;
		for(ll j=i-1;j>=0;j--){
			pre[i]+=a[i]-a[j];
		}
		//cout << i << "," << pre[i] << " " << m << "|";
		if(pre[i]<=m){
			ans = max(ans,i+1);
			l = i+1;
		}else{
			r = i-1;
		}
	}
	cout << ans << '\n';
	return 0;
}
