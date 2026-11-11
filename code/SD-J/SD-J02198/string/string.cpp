#include<iostream>
using namespace std;
long long n,a[200005];
char c[200005];
string s="0";
long long sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	
	int l=s.length()-1;
	
	for(int i=1;i<(l+1)/2;i++)
	{
		if(s[i]==s[l+1-i])
		{
		}
		else
		{
			sum++;
		}
		
	}
	cout<<sum;
	
	return 0;
}
