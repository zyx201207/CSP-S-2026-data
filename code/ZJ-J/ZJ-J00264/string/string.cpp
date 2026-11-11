#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
long long sum;
string s,s1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int p=1,q=n;
	long long cnt=0;
	while(sum>=1&&p<=q)
	{
		if(c[p]!=c[q])
		{
			if(a[p]==a[q])
			{
				cnt+=a[p];
				sum-=2*a[p];
				p++;
				q--;
			}
			else if(a[p]>a[q])
			{
				cnt+=a[q];
				a[p]-=a[q];
				sum-=a[q]*2;
				q--;
			}
			else if(a[p]<a[q])
			{
				cnt+=a[p];
				a[q]-=a[p];
				sum-=a[p*2];
				p++;
			}
		}
		else
		{
			if(a[p]<a[q])
			{
				a[q]-=a[p];
				sum-=2*a[p];
				p++;
			}
			else if(a[p]>a[q])
			{
				a[p]-=a[q];
				sum-=2*a[q];
				q--;
			}
			else
			{
				sum-=2*a[p];
				p++;
				q--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
