#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[501],len,g=1,num=0;
	char c[501];
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=a[i];j++)
		{
			s[g]=c[i];
			g++;
		}
	for(int i=1;i<=n;i++)
		len+=a[i];
	int j=g,i=0;
	int m;
	if(g%2==0) m=g/2;
	else m=g/2+1;
	for(int k=1;k<=m;k++)
	{
		if(j==i||i-j==1)
			break;
		if(s[i]!=s[j])
		{
			num++;
			j--;
			i++;
		}
	}
	cout<<num;
	return 0;
}	
