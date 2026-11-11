#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int n,s=0;
long long a[MAXN],cha[MAXN];
long long m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		long long sum=m;
		int t=0;
		for(int j=i;j>0;j--)
		{
			int x=a[i]-a[j];
			sum-=x;
			if(sum>=0)
			{
				t++;
			}
			else
			{
				break;
			}
		}
		s=max(s,t);
	}
	cout<<s;
	return 0;
}
