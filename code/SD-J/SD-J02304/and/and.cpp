#include<bits/stdc++.h>
using namespace std;
int n,m,a[300000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int ans=a[n];
	for(int i=n;i>n-m;i--)ans=ans&a[i];
	cout<<ans;
	return 0;
}
