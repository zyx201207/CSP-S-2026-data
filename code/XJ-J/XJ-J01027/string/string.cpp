#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1={0},s2={0},c;
	int i,n,h=0,j,l,a,t=1;
	cin>>n;
	for(i=1;i<=n;i++)
	{
    	cin>>a>>c[i];
		for(j=1;j<=a;j++)
		{
			s1=s1+c[i];
		}	
	}
	for(i=1;i<n;i++)
	{
		if(c[i]-'a'!=c[i+1]-'a')
		{
			t=0;
		}
	}
	if(t==1)
	{
		cout<<"0";
		return 0;
	}
	l=s1.size();
	for(i=l;i>0;i--)
	{
		s2=s2+s1[i];
	}
	for(i=0;i<l;i++)
	{
		if(s1[i]-'a'!=s2[i]-'a') h++;
	}
	if(h%2==0)
	{
		h=h/2;
	}
	else
	{
		h=(h+1)/2;
	}
	cout<<h;
	return 0;
}