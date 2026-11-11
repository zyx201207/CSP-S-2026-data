#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000000],ans=0,s[1000000];
signed main(){
	ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int p=0;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		while(a[i]*(i-p)-s[i]+s[p]>m)p++;
		ans=max(ans,i-p);
	}
	cout<<ans;
	return 0;
}