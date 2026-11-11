//西安翱翔中学 张奕纬 SN-J00842 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a,d;
	long long n,num=0,s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s>>d;
		for(int i=1;i<=s;i++)
		{
			a+=d;
		}
	}
	for(int i=0;i<=n/2;i++)
	{
		if(a[i]!=a[n-i])
		{
			num++;
		}
	}
	cout<<num;
	return 0;
}
