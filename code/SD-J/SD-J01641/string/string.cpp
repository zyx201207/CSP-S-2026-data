#include<bits/stdc++.h>
using namespace std;
long long m,n,sum=0;
string s;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>n>>c;
		for(int i=0;i<n;i++)
		{
			s=s+c;
		}
	}
	long long k=s.size();
	if(k%2==1)
	{
        for(int i=0;i<=k/2;i++)
		{
			if(s[i]!=s[k-i-1])
			{
				sum++;
			}
		}	
	}
	else
	{
		for(int i=0;i<k/2;i++)
		{
			if(s[i]!=s[k-i-1])
			{
				sum++;
			}
		}		
	}
	cout<<sum;
	return 0;
}
