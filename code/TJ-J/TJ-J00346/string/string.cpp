#include<bits/stdc++.h>
using namespace std;
string s,c;
long long n,a[100005];
int main(){
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	
	long long l,r;
	if(s.size()%2==0)
	{
		l=s.size()/2;
		r=s.size()/2+1;
	}
	else
	{
		l=s.size()/2;
		r=s.size()/2+2;
	}
	long long ans=0;
	for(int i=0;i<=l+1;i++)
	{
		for(int j=s.size()-1;j>=r-1;j--)
		{
			cout<<i<<j<<s[i]<<s[j];
			if(s[i]!=s[j])
			{
				
				s[j]=s[i];
				ans++;
			}
			i++;	 
		}
	}
	
	cout<<ans;	
	return 0;
} 
