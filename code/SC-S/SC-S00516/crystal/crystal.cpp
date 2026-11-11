#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,mx,f=1,ff=1;
int a[500005];
void solve(){
	for(int k=2;k<=n;k++){
		int mm=m,sum=0;
		for(int i=k;i>=1;i--){
			if(mm < a[k]-a[i]) break;
			mm-=(a[k]-a[i]);
			sum++;
		}
		mx=max(mx,sum);
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=i) f=0;
		if(i>=3) if(a[i]-a[i-1]!=a[i-1]-a[i-2]) ff=0;
	}
	if(f==1){
		int x=floor((sqrt(8*m+1)-1)/2.0)+1;
		cout << x;
		return 0;
	}
	if(ff==1){
		int aa=a[2]-a[1];
		int x=floor((sqrt(aa*aa+8*aa*m)-aa)/(aa*2.0))+1;
		cout << x;
		return 0;
	}
	sort(a+1,a+n+1);
	solve();
	cout << mx;
}