#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],sum=0,ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2;i<=n;i++){
		if(m>=(a[i]-a[i-1])*(i-1)){
			m-=(a[i]-a[i-1])*(i-1);
			ans++;
		}
	}	
	cout<<ans;
	return 0;
}
