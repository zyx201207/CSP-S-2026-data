#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string S,c;
	long long a,n,ans=0;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(long long i=0;i<a;i++)
		{
			S+=c;
		}
	}
	long long j=S.size()-1;
	for(long long i=0;i<S.size()/2;i++)
	{
		if(S[i]!=S[j])
		{
			ans++;
		}
		j--;
	}
	
	cout<<ans;
	

	
	
	
	return 0;
}
