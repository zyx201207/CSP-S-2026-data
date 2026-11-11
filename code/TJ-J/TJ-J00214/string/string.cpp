#include<bits/stdc++.h>
#include<vector>
#include<string>

int n;
bool flag=true;
int x,csum=0;
char c;
int maxxx=-1;
int pos=0;
using namespace std;
bool check(vector<char> v)
{
	for(int i=0;i<v.size();i++)
	{
		if(v[i]==c) 
		{
			pos=i;
			return false;
		}
	}
	return true;
}
//unsigned long long maxx(vector<unsigned long long> v2)
//{
// 	long long ans=-1234567890;
//	for(int i=0;i<v2.size();i++)
//	{
//		ans=max(ans,v2[i]);
//	}
//}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	int maxxx1;
	vector<char> v;
	vector<long long> v2;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>c;
		maxxx=max(maxxx,x); 
		maxxx1=maxxx;
		if(check(v)) 
		{
			v.push_back(c);
			v2.push_back(x);
		}
		else
		{
			v2[pos]+=x;
		}
		for(int j=1;j<=x;j++)
		{
			s+=c;
		}
	}
	string s1=s;
	reverse(s1.begin(),s1.end());
	for(int i=0;i<s1.length();i++)
	{
		if(s[i]!=s1[i])
		{
			flag=false;
			break;
		}
	}
	if(flag=true) cout<<0;
	else
	{
		if(csum%2==0)
		{
			long long ans=0;
			for(int i=0;i<v2.size();i++)
			{
				ans=max(ans,v2[i]);
			}
		}
		else
		{
			cout<<maxxx1;
		}
	}
}
