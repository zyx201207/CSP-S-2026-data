#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<bits/stdc++.h>
long long n,a,p,sum=0,ans=0;
int c,s ;
using namespace std;
int main()
{ 
	//freopen("string.in","r",stdin)
	//freopen("string.out","w",stdout)
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		sum+=a;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	int f=(sum-1)/2,t;
	if(sum%2==0)
	{
		t=sum/2;
	}
	else
	{
		t=sum/2+1;
	}
	for(int l=t;l<sum;l++)
	{
		p=t-f;
		if(s[t-p]!=s[i])
		{
			ans++;
		}
	}
	cout<<ans;
	//fclose(stdin)
	//fclose(stdout)
	return 0;
}
