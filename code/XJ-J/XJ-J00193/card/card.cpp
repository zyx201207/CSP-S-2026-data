#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005];
string x;
void find1()
{
	int flag=0,y=0;
	for (int i = 0; i < x.size(); i++)
	{
		for (int j = i+1; j < x.size(); j++)
		{
			if (a[i]==a[j])
			{
				y=j;
				flag=1;
			}
		}
	}
	if (flag==1)
	{
		string z;
		for (int i = y-1; i < x.size(); i++)
		{
			z+=x[i];
		}
		x=z;
	}
	return;
}
void ff(int st)
{
	for (int i = st; i <= n; i++)
	{
		find1();
		x+=(a[i]+'0');
	}
	find1();
	for (int i = 0; i < x.size(); i++)
	{
		b[x[i]-'0']++;
	}
	return;
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	cin>>n>>m;
	for (int i = 1; i <= n; i++)
	{
		cin>>a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		ff(i);
		x="";
	}
	for (int i = 1; i <= m; i++)
	{
		cout<<b[i]<< " ";
	}
	return 0; 
}
