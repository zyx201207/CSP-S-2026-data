#include<bits/stdc++.h>
using namespace std;
struct Node
{
	long long x;
	char y;
}a[201000];
long long n,t,s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
	}
	t=n;
	for(int i=1;;)
	{
		if(i>=t) break;
		if(a[i].y==a[t].y)
		{
			if(a[i].x>a[t].x)
			{
				a[i].x-=a[t].x;
				a[t].x=0;
				t--;
			}
			else
			{
				a[t].x-=a[i].x;
				a[i].x=0;
				i++;
				if(!a[t].x) t--;
			}
		}
		else
		{
			s+=min(a[i].x,a[t].x);
			if(a[i].x>a[t].x)
			{
				a[i].x-=a[t].x;
				a[t].x=0;
				t--;
			}
			else
			{
				a[t].x-=a[i].x;
				a[i].x=0;
				i++;
				if(!a[t].x) t--;
			}
		}
	}
	cout<<s;
	return 0;
}
/*
3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b


*/