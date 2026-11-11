#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long a[N],n,v,c;
string s,cc,vv;
int uu=1,kk=1;
set<string>d;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==2)
	{
		for(int i=1;i<=n;i++)
		{
			string b;
			cin>>a[i]>>b;
			d.insert(b);
			if(d.size()==1&&uu==1)
			{
				cc=b;
				uu++;
			}
			else if(kk==1)
			{
				vv=b;
			}
			if(cc==b)
			{
				c+=a[i];
			}
			else
			{
				v+=a[i];
			}
			ans+=a[i];
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			string b;
			cin>>a[i]>>b;
			d.insert(b);
			ans+=a[i];
		}		
	}
	if(d.size()==1)
	{
		cout<<"0";
		return 0;
	}
	if(n==1)
	{
		cout<<"0";
		return 0;
	}
	if(n==2||d.size()==2)
	{
		if(d.size()==1)
		{
			cout<<"0";
		}
		else
		{
			cout<<min(c,v);
			return 0;
		}
	}
	return 0;
} 
