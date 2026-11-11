#include<bits/stdc++.h>
using namespace std;
long long n,nowi=1,sum,ans;
const long long MAX_N=2e5;
char s[MAX_N];
long long a;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(long long i=0;i<n;i++)
	{
		cin>>a>>c;
		for(long long j=sum+1;j<=sum+a+1;j++)
		{
			s[j]=c;
		}
		sum+=a;
	}
	for(long long i=0;i<sum;i++)
	{
		if(s[i]!=s[sum-i+1])
		{
			ans++;
			s[sum-i+1]=s[i];
		}
	}	
	cout<<ans-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
