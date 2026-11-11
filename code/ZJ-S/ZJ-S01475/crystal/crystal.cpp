#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[500010],m;
int s[500010];
int l=0;
int ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	s[0]=0;
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		while((a[i]*(i-l)-(s[i]-s[l]))>m)l++;
		ans=max(ans,i-l);
	}
	cout<<ans;
	
	return 0;
}