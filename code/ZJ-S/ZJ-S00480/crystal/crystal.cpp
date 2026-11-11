#include<bits/stdc++.h>
using namespace std;
int n,nl;
long long m,a[501000];
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long now=0,ans=1;
	for(int i=1;i<=n;i++){
		now+=(a[i]-a[i-1])*(i-nl-1);
		while(now>m)now-=(a[i]-a[nl++]);
		ans=max(ans,(long long)i-nl);
	}
	cout<<ans;
	return 0;
}
