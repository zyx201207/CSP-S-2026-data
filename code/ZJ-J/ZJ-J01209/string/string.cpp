#include<bits/stdc++.h>
using namespace std;
vector<long long>a2={};
vector<char>c2={};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long A;
		char C;
		cin>>A>>C;
		a2.push_back(A);
		c2.push_back(C);
	}
	long long cnt=0;
	long long cntbg=0;
	long long cnted=a2.size()-1;
	while(cntbg<cnted)
	{
		if(c2[cntbg]!=c2[cnted]) cnt+=min(a2[cntbg],a2[cnted]);
		a2[cntbg]-=min(a2[cntbg],a2[cnted]);
		a2[cnted]-=min(a2[cntbg],a2[cnted]);
		if(a2[cntbg]<=0)
		{
			cntbg++;
		}
		if(a2[cnted]<=0)
		{
			cnted--;
		}
	}	
	cout<<cnt;
	return 0;
}