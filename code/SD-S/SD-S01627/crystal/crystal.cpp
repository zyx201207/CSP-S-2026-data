#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000010],b[1000010],l=1,r=1,Ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	while(l<=n)
	{
		long long c=a[r]*(r-l)-b[r-1]+b[l-1];
		if(c<=m)Ans=max(Ans,r-l+1);
		if(c<=m&&r<n)r++;
		else l++;
	}
	cout<<Ans<<"\n";
	return 0; 
}
