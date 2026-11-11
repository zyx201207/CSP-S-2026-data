#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=1,spend=0,ans=1;
	while(r<=n){
		r++;
		spend+=(r-l)*(a[r]-a[r-1]);
		if(spend>m){
			while(spend>m){
				spend-=(a[r]-a[l]);
				l++;
			}
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
/* 
Hello
*/
