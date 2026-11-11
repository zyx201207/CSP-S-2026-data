#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n,a;
	long long cnt=0;
	string d={0};
	string c={0};
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		for(int j=i;j<a;j++)
		{
			cin>>c[j];
			d+=c[j];
		}
	}
	
	reverse(c.begin(),c.end());
	for(int i:d)
	{
		if(d[i]!=c[i])
		{
			cnt++;
		}
		else
		cout<<"0";
	}
	cout<<cnt/2;
	return 0;
}
