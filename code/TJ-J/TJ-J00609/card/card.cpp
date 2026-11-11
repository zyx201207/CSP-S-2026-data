#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,k=1,a[500005],b[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	while(k<=n)
	{
		long long l=a[k];
		int id;
		string s="";
		for(int i=k;i<=n;i++)
		{
			for(int j=n;j>=i;j--)
			{
				if(l==a[j])
				{
					s+=char(a[j]+'0');
					l=a[j+1];
					i=j+1;
					id=i;
				}
			}
		}
		for(int i=id;i<=n;i++)
		{
			s+=char(a[i]+'0');
		}
		for(int i=0;i<=s.size()-1;i++)
		{
			b[int(s[i]-'0')]++;
		}
		k++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
