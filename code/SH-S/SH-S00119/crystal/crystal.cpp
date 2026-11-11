#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int c=0;
	for(int i=1,j=1;i<=n;i++){
		c+=(i-j)*(a[i]-a[i-1]);
		while(c>m){
			c-=a[i]-a[j];
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
}
