#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],s[500005];
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=0,ans=0;
	while(r<n){
		while(++r<=n&&a[r]*(r-l)-s[r-1]+s[l-1]<=m);
		ans=max(ans,(--r)-(l++)+1);
	}
	cout<<ans;
	return 0;
}
