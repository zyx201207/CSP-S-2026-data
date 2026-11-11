#include<bits/stdc++.h>
using namespace std;
string S;
long long L=0;
long long sum=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	while(n--)
	{
		long long m;
	    
		string s;
		cin>>m>>s;
		L+=m;
		if(L>=100000000)continue;
		while(m--)
		{
			S+=s;
		}
		}
		if(L>=100000000)
		{
			cout<<L/2;
			return 0;
			}
	for(long long i=0;i<=L/2;i++)
	{
		if(S[i]!=S[L-1-i])
		{
			sum+=1;
		}
		}
		cout<<sum;
	return 0;


}
