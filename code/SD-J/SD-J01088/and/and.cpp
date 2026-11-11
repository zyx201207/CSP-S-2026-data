#include<bits/stdc++.h>	
using namespace std;
long long n,m;
int a[200010]; 
bool cmp(int a,int b)
{
	return a>b;
}
void solve1()
{
	int maxx=-0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		maxx=max(maxx,a[i]);
		
	}
	cout<<maxx;
}
void solve2()
{
	int maxx=-0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			{
				continue;
			}
			else
			{
				maxx=max(maxx,a[i]&a[j]);
			}
			
		}
		
	}
	cout<<maxx;
}
int main(){



	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		solve1();
		return 0;
	}
	if(m==2)
	{
		solve2();
		return 0;
	}
	else
	{
		sort(a+1,a+n+1,cmp);
		int sum=a[1];
		cout<<a[m];
	}
	return 0;
}
