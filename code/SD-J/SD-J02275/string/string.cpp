#include<bits/stdc++.h>
using namespace std;
vector<int > a;
vector<char > c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,flag,ans=0;
	cin>>n;
	string s;
	int x;
	char y;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		a.push_back(x);
		c.push_back(y);
	}
	int i=0,j=n-1;
	while(i<j)
	{
		flag=min(a[i],a[j]);
		if(c[i]!=c[j])
		{
			ans+=flag;
			a[i]-=flag;
			a[j]-=flag;
		}
		else if(c[i]==c[j])
		{
			a[i]-=flag;
			a[j]-=flag;
		}
		if(a[i]==0)
			i++;
		if(a[j]==0)
			j--;
	}
	cout<<ans;
	return 0;
}
