#include <bits/stdc++.h>
#include <vector>
using namespace std;
long long n,ans,cut;
int z;
vector<long long> a;
vector<char> c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ans,cut=0;
	if(n==1)
	{
		cout<<"0";
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		int q;
		char w;
		cin>>q>>w;
		a.push_back(q);
		c.push_back(w);
	}
	int b=0,l=n-1;
	while(b!=l&&z<n)
	{
		if(c[l]==c[b])
		{
			if(a[b]<a[l])
			{
				a[l]-=a[b];
				b+=1;
				z++;
			}
			else if(a[b]>a[l])
			{
				a[b]-=a[l];
				l-=1;
				z++;
			}
			else
			{
				l-=1;
				b+=1;
				z+=2;
			}			
		}
		else
		{
			if(a[b]<a[l])
			{
				ans+=a[b];
				a[l]-=a[b];
				b+=1;
				z++;
			}
			else if(a[b]>a[l])
			{
				ans+=a[l];
				a[b]-=a[l];
				l-=1;
				z++;
			}
			else
			{
				ans+=a[b];
				l-=1;
				b+=1;
				z+=2;
			}
		}
	}
	cout<<ans;
	return 0;
} 
