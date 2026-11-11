#include<bits/stdc++.h>
using namespace std;
long long n,m,memo,a[3250000],b[3250000],c[3250000],pp,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]+b[i-1];
		c[i]=a[i]*i-b[i];
	}
//	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
//	cout<<endl;
//	for(int i=1;i<=n;i++) cout<<b[i]<<' ';
//	cout<<endl;
//	for(int i=1;i<=n;i++) cout<<c[i]<<' ';
//	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		while(c[i]-(a[i]*memo-b[memo])>m) memo++;
		pp=i-memo;
		if(pp>ans) ans=pp;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
