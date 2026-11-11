#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while (t--)
	{
		ans=0;
		cin>>n>>d;
		for (int i=1;i<=n;i++)cin>>a[i];
		 for (int i=n;i>=1;i--)
		 {
		 	for (int j=i-2;j>=1;j--)
		 	{
		 		if(a[i]-a[j]<=d)ans++; 
			 } 
		 }
		 cout<<ans-1<<'\n';
	 } 
	return 0; 
}
