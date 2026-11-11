#include<bits/stdc++.h>
using namespace std;
int a[1005],s;
int main()
{
//	freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n,c=0;
	bool f;
	string s,s1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s1=s1+s;
		}
	}
	int l=s1.size();
	int ans=0;
	for(int i=1;i<=n;i++)
	{ 	
		for(int j=1;j<=n;j++)
		{
			if(s[i]==s[j+1]&&f==true)
			{
				cout<<"0";
				return 0;
			}
			else if(s1[j]!=s1[l-j+1]&&j==1)
				swap(s1[j+1],s1[l-j+1]);
				ans++;
				f=false;
			}
		}
			cout<<ans/4-1;
	}
	 

