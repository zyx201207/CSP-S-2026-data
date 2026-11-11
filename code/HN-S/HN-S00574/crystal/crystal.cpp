#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
#include<windows.h>
using namespace std;
long long n,m,zj=0,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int a[500001];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]!=a[i+1])
		{
			break;
	 	} 
		else
		{
			cout<<n;
			return 0;
		}
	} 
	sort(a,a+n);
	if(n%2==0)
	{
		int sum=0;
		for(int i=0;i<n;i++)
		{
			sum+=a[i];
		}
		zj=floor(sum/n);
	}
	else if(n%2!=0)
	{
		int t=floor(n/2),t1=n;
		t1-=t;
		zj=a[t1-1];
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==zj)
		{
			ans++;
		}
		if(a[i]<zj)
		{
			ans++;
			m-=zj-a[i];
		}
	}
	printf("%d",ans);
	return 0;
}                 
