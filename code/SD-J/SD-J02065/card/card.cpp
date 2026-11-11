#include<bits/stdc++.h>
#include<cstdio>

using namespace std;
int a[510000],cnt[310000];
int n,m;
int shu(int x)
{
	string s;
	for(int i=x;i<=n;i++)
	{
		if(s.find(a[i])!=-1)
		{
			s.erase(s.find(a[i])+1);
		}
		else{
			s+=a[i];
		}
		
	}
	int len=s.size();
	for(int i=0;i<=len;i++)
	{
		cnt[s[i]]++;
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >>n >>m;
	for(int i=1;i<=n;i++)
		{
			cin>> a[i];
		}
	for(int i=1;i<=n;i++)
	{
		shu(i);
		
	}
	for(int i=1;i<=m;i++)
	{
		cout <<cnt[i]<< " ";
	}
	return 0;
}
