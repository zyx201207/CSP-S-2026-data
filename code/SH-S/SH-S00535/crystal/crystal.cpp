#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int ans=1,l=1,cos=0;
	for(int i=2;i<=n;i++){
		cos+=(a[i]-a[i-1])*(i-l);
		while(cos>m){
			cos-=(a[i]-a[l]);
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout << ans;
	
	
	return 0;
} 
