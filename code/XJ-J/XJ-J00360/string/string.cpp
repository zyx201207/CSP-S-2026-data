#include <bits/stdc++.h>
using namespace std;
int n,p,num,sum,ans;
char a[100005],x;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	bool m=true;
	cin>>n;
	int num=1;
	for(int i=1;i<=n;i++)
	{
		cin>>p>>x;
		sum+=p;
		for(int j=num;j<=num+p-1;j++)
		{
			a[i]=x;
		}
	}
	for(int i=1;i<=sum/2;i++)
	{
		for(int j=sum;j>=sum/2;j--)
		{
			if(a[i]-'a'!=a[j]-'a')
			{
				m=false;
				ans++;
			}
		}
	}
	if(m)
	{
		cout<<0;
	}
	else
	{
		cout<<ans;
	}
}