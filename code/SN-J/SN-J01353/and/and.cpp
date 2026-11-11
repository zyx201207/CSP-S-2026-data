#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ans=4294967295;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(1+a,1+a+n);
	for(int i=n;i>=n-m+1;i--)ans=ans&a[i];
	cout<<ans;
	return 0;
}

