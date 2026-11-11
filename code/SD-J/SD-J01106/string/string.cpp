#include<bits/stdc++.h>
using namespace std;
long long int n,sum=0,num=0,aa=-1,bb=-1,cc,aaa=-1,bbb=-1,ccc,d;
string o="";
struct abc
{
	long long int a;
	char b;	
};
abc k[200020];
int ff(int i)
{
	int m=0;
	if(i<=k[0].a)
		return 0;
	
	while(i>k[m+1].a)
	{
		
		i-=k[m].a;
		m++;
	}
	bb=i;
	return m+1;
}
int ff2(int i)
{
	int m=0;
	if(i<=k[0].a)
		return 0;
	
	while(i>k[m+1].a)
	{
		i-=k[m].a;
		m++;
	}
	bbb=i;
	return m+1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>k[i].a>>k[i].b;
		num+=k[i].a;/*
		for(int j=0;j<k[i].a;j++){
			
			o+=k[i].b;}*/
	}
	
	aa=ff(1);
	cc=1;
	aaa=ff2(n);
	ccc=n;
	for(int i=1;i<=(num+1)/2;i++)
	{
		//cout<<ff(i)<<"  "<<ff(n-i+1)<<"\n";
		if(i-cc+bb>k[aa].a)
		{
			aa=ff(i);
			cc=i;
		}
		else
			cc++;bb++;
		if(bbb<1)
		{
			aaa=ff2(i);
			ccc=i;
		}
		else
			ccc--;bbb--;
		if(k[aa].b!=k[aaa].b)
			sum++;/*
		if(o[i]!=o[n-i+1])
			sum++;*/
	}
	cout<<sum;
	
}
