#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,maxx=0;
	int a[5005];
	long long ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		ans+=a[i];
	}
	sort(a+1,a+n+1);
	int g=lower_bound(a+1,a+n+1,ans/n)-a;
	for(int i=a[g-1];i<=a[g];i++)
	{
		int ans=0,s=m;
		for(int j=1;j<=n;j++)
		{
			if(a[j]>i) break;
			s-=(i-a[j]);
			if(s<0)	break;		
			ans++;
		}
		if(ans>maxx) maxx=ans;
	}
	cout<<maxx<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
