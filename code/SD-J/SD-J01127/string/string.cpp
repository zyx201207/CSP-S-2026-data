#include<bits/stdc++.h>
using namespace std;
int n;string s;long long sum;long long num;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long a[n];
	char c[n];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
			s+=c[i];
		sum+=a[i]; 
	}
	if(sum%2==1)	--sum;
	sum/=2;
	for(long long i=1;i<=sum;i++)
	{
		if(s[s.size()-i]!=s[i-1])	num++;
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout); 
	return 0;
 } 
