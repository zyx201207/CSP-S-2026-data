#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010];
long long n,m,m2,soldier;
int check()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==soldier) cnt++;
	}
	return cnt;
}
int check2()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]==soldier+1) cnt++;
	}
	return cnt;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	m2=m;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		b[i]=a[i];
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	int sum=0;
	for(int i=1;i<=n;i++)
		sum+=a[i];
	//cout<<sum;
	soldier=sum/n;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<soldier&&m!=0)
		{
			if(soldier-a[i]<=m)
			{
				m-=(soldier-a[i]);
				a[i]=soldier;
			}
		}
	}
	int ans1=check();
	for(int i=1;i<=n;i++)
	{
		if(b[i]<soldier+1&&m2!=0)
		{
			if(soldier+1-b[i]<=m2)
			{
				m2-=(soldier+1-b[i]);
				b[i]=soldier+1;
			}
		}
	}
	int ans2=check2();
	cout<<max(ans1,ans2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}