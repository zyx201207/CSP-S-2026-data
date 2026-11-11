#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string a="";
	while(n--)
	{
		int t;
		cin>>t;
		char c;
		cin>>c;
		for(int i=1;i<=t;i++)
		{
			a+=c;
		}
	}
	long long len=a.size();
	long long cnt=0;
	for(int i=0;i<len/2;i++)
	{
		if(a[i]!=a[len-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
