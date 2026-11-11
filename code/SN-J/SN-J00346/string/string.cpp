#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string3.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,x=0,num=0;
	string s,l;
	char c;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		cin>>c;
		x=x+a;
		for(int j=0;j<a;j++)
		{
			s[j]=c;
		}
	}	
	int h=0,j;
	for(j=x-1;j>=0;j--)
	{
		l[j]=s[h];
		h++;
	}
	h=0;
	while(h!=x/2+1)
	{
		if(l[j]!=s[h])
		{
			num=num+1;
		}	
		j--;
		h++;
	}
	cout<<num;
	return 0;
}
