#include<bits/stdc++.h>
using namespace std;
long long a[200010],b[200010];
long long n,m;
long long maxx=-1;
long long x=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=a[n];
	for(int i=1;i<=m-1;i++)
	{
		ans=ans&a[n-i];
	}
	cout<<ans;
	return 0;
}
 
