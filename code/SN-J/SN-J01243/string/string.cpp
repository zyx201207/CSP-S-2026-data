#include<bits/stdc++.h>//¡Ì... 
using namespace std;
freopen("string.in","r",stdin)
freopen("string.out","w",stdout)
int main()
{
	int n,a,l=0,sum=0;
	char s[1000005],c;//s·¶Î§²»¹» 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s[l+j]=c;
			l++;
		}
	}
	for(int i=1;i<=l;i++)
	{
		if(s[i]!=s[l+1-i])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
