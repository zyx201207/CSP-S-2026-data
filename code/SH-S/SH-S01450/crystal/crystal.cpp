#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long s[500005];
long long d,ans=1;
int main()
{
 	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++)
 		cin>>a[i];
 	sort(a+1,a+n+1);
 	for(int i=1;i<=n;i++)
 		s[i]=s[i-1]+a[i];
 	for(long long i=1;i<=n;i++)
 	{
 		long long j=i+ans;
 		while(j<=n)
 		{
		 	d=(j-i+1)*a[j]-(s[j]-s[i-1]);
 			//cout<<i<<" "<<j<<" "<<d<<endl;
 			if(d<=m)
 				ans=max(ans,j-i+1);
 			else
 				break;
			j++;
		}
	}
	cout<<ans<<endl;
 	return 0;
}
