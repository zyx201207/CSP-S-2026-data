#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s=0,j=0;
	ll ans=0;
	cin>>n;
	vector<ll> x,sx;
	vector<char> c;
	for(int i=0;i<n;i++)
	{
		int a;
		char b;
		cin>>a>>b;
		s+=a;
		
		if(i>0&&b==c[j-1]) {
			x[j-1]+=a;
			sx[j-1]+=a;
		}
		else
		{
			sx.push_back(s);
			x.push_back(a);
			c.push_back(b);
			++j;
		}
	}
	if((int)c.size()==1) { cout<<"0"; return 0; }
	
	int flag=0;
	
	if(s%2==1) flag=(s+1)/2;
	for(int i=0;i<sx.size();i++)
	{
		if(sx[i]>=flag)
		{
			x[i]--;
			break;
		}
	}

	ll l=0,r=x.size()-1,sum=0;
	while(l<=r)
	{
		if(c[l]!=c[r])
		{
			ans+=x[r];
			sum+=x[r];
		}
		else
		{
			if(x[r]<x[l])
			{
				r--;
			}
			else if(x[r]>x[l])
			{
				l++;
			}
			else
			{
				l++;
				r--;
			}
			continue;
		}
		if(sum>=x[r])
		{
			r--;
		}
		else if(sum>x[l])
		{
			sum-=x[l];
			l++;
		}
		else if(sum==x[l])
		{
			l++;
			sum=0;
			r--;	
		}
		
	}
	cout<<ans;
	return 0;
}

