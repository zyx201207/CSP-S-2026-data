#include<bits/stdc++.h>
using namespace std;
struct mys
{
	long long a;
	char c;
}m[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	cin>>n;
	for(int i=0;i<n;i++) cin>>m[i].a>>m[i].c;
	long long end=n-1,start=0;
	for(int i=0;i<n;i++)
	{
		if(m[start].c!=m[end].c)
		{
			if(m[start].a>m[end].a)
			{
				sum+=m[end].a;
				m[start].a-=m[end].a;
				end--;
			}
			if(m[start].a==m[end].a)
			{
				sum+=m[end].a;
				m[start].a=0;
				m[end].a=0;
				end--;
				start++;
			}
			if(m[start].a<m[end].a)
			{
				sum+=m[start].a;
				m[end].a-=m[start].a;
				m[start].a=0;
				start++;
			}
		}
	}
	cout<<sum;
	return 0;
}
