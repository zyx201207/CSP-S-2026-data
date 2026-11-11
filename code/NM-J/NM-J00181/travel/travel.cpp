#include<bits/stdc++.h>
using namespace std;
int a[10105];
string s;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}
	string zfc1;
	for(int i=1;i<=n;i++)
	{
	
		for(int j=1;j<=a[i];j++)
		{
			zfc1+=s[i];
		}
	}
	int res=0;
	int len=zfc1.size();
	for(int i=1;i<=zfc1.size();i++)
	{
		int l=0,r=s.size()-1;
		while(zfc1[l]!=zfc1[r])
		{
			
			l++;r--;
			for(int ji=97;ji<=122;ji++)
			{
				zfc1[i]=(char)ji;
				
			}
			
		}
		res++;
	}
	cout<<res;
}
