#include<bits/stdc++.h>
using namespace std;
string s,s1,s2;
int n,ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a=0;
		string x;
		cin>>a;
		cin>>x;
		for(int i=1;i<=a;i++)
		{
			s+=x; 
		}
	}
	//ÊäÈë
	int ls=s.size(),ls1=s.size();
	if(ls%2==0)
		ls=ls/2;
	else
		ls=ls/2+1;
	for(int i=0;i<ls;i++)
	{
		s1[ls-i-1]=s[i];
	}
	int k=0;
	for(int i=ls-1;i<=ls1;i++)
	{
		s2[k++]=s[i];
	 } 
	
	for(int i=0;i<ls;i++)
	{
		if(s1[i]!=s2[i])
			ans++;
	}
	cout<<ans;
	return 0;
} 
