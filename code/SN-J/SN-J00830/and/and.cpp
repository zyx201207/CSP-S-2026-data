//李铭宸 西安交通大学附属中学 SN-J00830
#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int n,m,maxn=-1;
int an[1000005];
void first()
{
	sort(a+1,a+n+1);
	cout<<a[1];
}
void scend( )
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int s=a[i]&a[i+1];
			maxn=max(maxn,s);
		}
	}
	cout<<maxn;
}
void bl()
{
	an[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		an[i]=an[i-1]&a[i];
	}
	int ans[1000005]={};
	for(int i=1;i<=n-m;i++)
	{
		ans[i]=abs(an[i]-an[m+i]);
	} 
}
int main() 
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1) first();
	else if(m==2) scend();
	else bl();
	return 0;
}
