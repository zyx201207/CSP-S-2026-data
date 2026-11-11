#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
	int n,m,l,b=1;
	string s1,s2,s;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		l=a[i];
		for(int j=1;j<=n;j++)
		{
			while(l>0)
			{
				s1=l%2+'0';
				l=l/2;
			}
			reverse(s1.begin(),s1.end());
			for(int k=1;k<=m;k++)
			{
				if(s2=="")
				{
					s2=s1;
					s1="";
				}
				else if(s2==s1&&k!=1){
					b=b*2;
				}
			}
			
		}
	}
	cout<<a;
}