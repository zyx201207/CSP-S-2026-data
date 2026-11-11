#include <bits/stdc++.h>
using namespace std;

int a[200010];

string W(int n)
{
	int i=0;
	string s,s1;
	while(n!=0)
	{
		n/=2;
		s[i]=n%2;
		i++;
	}
	for(int i=0;i<s.size();i++)
	{
		s1[i]=s[s.size()-i];
	}
	return s1;
}

int andd(string s,string s1)
{
	string s2,s3;
	int sum=0;
	for(int i=0;i<max(s.size(),s1.size());i++)
	{
		if(s[i]==s1[i])
			s2[i]=1;
		else
			s2[i]=0;
	}
	for(int i=0;i<s2.size();i++)
	{
		s3[i]=s2[s2.size()-i];
	}
	for(int i=0;i<s3.size();i++)
	{
		sum+=s3 [i]*pow(2,i+1);
	}
	return sum;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	
	long long n,m,maxx=0,sum=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			sum=andd(W(a[i]),W(a[j]));
			if(sum>maxx)
				maxx=sum;
		}
	}
	cout<<maxx;
	return 0;
}
