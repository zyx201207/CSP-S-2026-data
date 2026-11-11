#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int p;
	cin>>p;
	int n[p];
	string s[p];
	for(int i=0;i<p;i++)
	{
		cin>>n[i];
		cin>>s[i];
	}
	string y="";
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<n[i];j++)
		{
			y+=s[i];
		}
	}
	string h="";
	for(int i=y.length()-1;i>=0;i--)
	{
		h+=y[i];
	}
	int num=0;
	int j=h.length()-1;
	if(y==h)
	{
		cout<<"0";
	}
	else
	{
		for(int i=0;i<y.length();i++)
		{
			if(h[i]!=h[j])
			{
				num+=1;
			}
			j-=1;
		}
		cout<<num/2;
	}
	return 0;
}