#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string str;
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long a;
		char b;
		cin>>a>>b;
		for(int i=1;i<=a;i++)
			str+=b;
	}
	n=str.size();
	long long ans=0;
	for(long long i=1;i<=n/2;i++)
		if(str[i]!=str[n-i+1])
			ans++;
	cout<<ans;
	return 0;
}
