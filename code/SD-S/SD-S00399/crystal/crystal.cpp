#include<bits/stdc++.h>
#define int long long
#define N 1001000
using namespace std;
int n,m,a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int ans=1;
	for(int i=1,j=2,mm=0;i<=n&&j<=n;j++){
		mm+=(a[j]-a[j-1])*(j-i);
		while(mm>m){
			mm-=(a[j]-a[i]);
			i++;
		}
		ans=max(ans,j-i+1);
	}
	cout<<ans;
	return 0;
} 
