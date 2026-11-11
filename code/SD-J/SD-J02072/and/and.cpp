#include<bits/stdc++.h>
using namespace std;
int awy(int a,int b)
{
	string s="01",s1="",s2="",s3,sz="";
	int sum=0,n=1;
	while(a)
	{
		s1=s[a%2]+s1;
		a/=2;
	}
		while(b)
	{
		s2=s[b%2]+s2;
		b/=2;
	}
	if(s1.size()>s2.size())
	{
		s3=s1;
		s1=s2;
		s2=s3;
	}
	for(int i=s1.size()-1;i>=0;i--)
	{
		if(s1[i]==s2[i])sum+=n*(s1[i]-'0');
		n*=2;
	}
	return sum;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a,b,max=-1;
	cin>>a>>b;
	int arr[a];
	for(int i=0;i<a;i++)cin>>arr[i];
	if(b==1)max=0;
	if(b==2)
	{
		for(int i=0;i<a-1;i++)
		{
		
			for(int j=i+1;j<a;j++)
			{
				if(awy(arr[i],arr[j])>max)max=awy(arr[i],arr[j]);
			}
		}
	}
	if(b==3)
	{
		for(int i=0;i<a-2;i++)
		{
		
			for(int j=i+1;j<a-1;j++)
			{
				for(int y=j+1;y<a;y++){if(awy(awy(arr[j],arr[y]),arr[i])>max)max=awy(awy(arr[j],arr[y]),arr[i]);
				}
			}
		}
	}
	cout<<max;
}
