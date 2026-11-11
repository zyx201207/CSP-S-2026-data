#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[200002];
int beifen[200002];
int now=0;

void pop(int id)
{
	for(int i=id+1;i<=now;i++)
	{
		a[i]=0;
	}
}

int search(int k)
{
	for(int i=1;i<=now;i++)
	{
		if(a[i]==k)
		{
			return i;
		}
	}
	return 0;
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> beifen[i];
	}
	int ans[m+1];
	for(int i=1;i<=m;i++)
		ans[i]=0;
	for(int q=1;q<=n;q++)
	{
		now=0;
		for(int i=q;i<=n;i++)
		{
			now++;
			a[now]=beifen[i];
			int booll=search(a[now]);
			if(booll)
			{
				pop(booll);
				now=booll;
			}
		}
		for(int i=1;i<=now;i++)
		{
			ans[a[i]]++;
		}
		for(int i=0;i<200002;i++)
		{
			a[i]=0;
		}
	}
	for(int i=1;i<=m;i++)
		cout << ans[i] << " ";
	return 0;
}
