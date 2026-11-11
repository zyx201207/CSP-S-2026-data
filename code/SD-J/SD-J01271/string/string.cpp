#include<bits/stdc++.h>
using namespace std;
struct d
{
	long long a;
	char c;
};
d a[200001];
long long n,ans=0;
string s;
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
		cin>>a[i].a>>a[i].c;
	}
	int i=1,j=n;
	while(i<j)
	{
		if(a[i].c!=a[j].c)
		{
			if(a[i].a<a[j].a)
			{
				ans+=a[i].a;
				a[j].a-=a[i].a;
				i++;
				continue;
			}
			if(a[i].a>a[j].a)
			{
				ans+=a[j].a;
				a[i].a-=a[j].a;
				j--;
				continue;
			}
			if(a[i].a==a[j].a)
			{
				ans+=a[j].a;
				i++;
				j--;
				continue;
			}
		}
		if(a[i].c==a[j].c)
		{
			if(a[i].a<a[j].a)
			{
				a[j].a-=a[i].a;
				i++;
				continue;
			}
			if(a[i].a>a[j].a)
			{
				a[i].a-=a[j].a;
				j--;
				continue;
			}
			if(a[i].a==a[j].a)
			{
				i++;
				j--;
				continue;
			}
		}
	}
	cout<<ans;
	return 0;	
} 
