#include<bits/stdc++.h>
using namespace std;
int a[500010],t[300010];
queue<int> b;
int n,m;
void fang(int a[],queue<int> b[])
{
	if(b) continue;
	else return;
	while(b)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=-1)
			{
				a[i]=b.top();
				b.pop();
			}
			for(int j=1;j<=j-1;j++)
			{
				if(a[j]==a[i])
				{
					for(int x=j;j<=i;j++)
					{
						if(a[j]!=-1)
						{
							b.push(a[j]);
							a[j]=-1;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=-1)
			t[a[i]]++;
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j>=1;j--)
		{
			if(a[j]!=-1)
				swap(a[i],a[j]);	
		} 
	fang(a,b);
}
int main()
{
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		for(int j=1;j<=j-1;j++)
		{
			if(a[j]==a[i])
			{
				for(int x=j;j<=i;j++)
				{
					if(a[j]!=-1)
					{
						b.push(a[j]);
						a[j]=-1;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=-1)
			t[a[i]]++;
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j>=1;j--)
		{
			if(a[j]!=-1)
				swap(a[i],a[j]);	
		} 
	fang(a,b);
	for(int i=1;i<=m;i++)
		cout << t[i] << ' '; 
}
