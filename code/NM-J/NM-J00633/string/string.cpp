#include <bits/stdc++.h>
using namespace std;
int main()
{freopen("r","string.in",stdin);
	freopen("w","string.out",stdout);
	string a;
	vector< string> ab;
	long long sum=0;
	long long b=0;
	long long n=0;
	long long zhi=0;
	cin>>n;
	for(long long i=0;i<n;i++)
	{cin>>b>>a;
		sum+=b;
		for(long long j=0;j<b;j++)
		{ab.push_back(a);}}
	
	if(sum%2==0)
	{
		for(long long i=0;i<sum/2;i++)
	{if(ab[i]!=ab[sum-(i+1)])
		{zhi=zhi+1;
			};}
		};
		
		
if(sum%2!=0)
{sum=sum-1;	
	for(long long c=0;c<(sum/2);c++)
	{if(ab[c]!=ab[sum-(c+1)])
		{zhi=zhi+1;
			};}
			};	


cout<<zhi;

	return 0;
}
