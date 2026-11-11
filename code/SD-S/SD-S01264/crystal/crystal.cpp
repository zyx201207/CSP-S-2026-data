#include <bits/stdc++.h>
using namespace std;
int n,ans;const int N=5e5+5;
long long m,s,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int p1=n,p2=n;
	for(;p1;--p1){
		while(p2>1&&a[p1]-a[p2-1]+s<=m)s+=(a[p1]-a[--p2]);
		ans=max(ans,p1-p2+1);
		s-=(p1-p2)*(a[p1]-a[p1-1]);
	}
	cout<<ans;
	return 0;
}
