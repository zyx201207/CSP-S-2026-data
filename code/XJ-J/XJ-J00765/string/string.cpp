#include<bits/stdc++.h>
using namespace std;
int n,sum,cnt;
string s="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int num;
		cin>>num;
		sum+=num;
		char a;
		cin>>a;
		for(int j=0;j<num;j++)
		{
			s+=a;
		}
	}
	for(int i=0,j=sum-1;i<sum/2&&j>=sum/2;i++,j--)
	{
		if(s[i]!=s[j]) cnt++;
	}
	cout<<cnt;
	return 0;
}