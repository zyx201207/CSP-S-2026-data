#include<bits/stdc++.h>
using namespace std;
long long int n,x,y=0,m=0,sum=0;
char z;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x>>z;
		m+=x;
		for(int j=y;j<m;j++)
		{
			s[j]=z;
		}
		y+=x;
	}
	for(int i=0,j=m-1;i<m/2;++i)
	{
		if(s[i]!=s[j])
		{
			sum++;
		}
		j-=1;
	}
	cout<<sum;
	return 0;
}
