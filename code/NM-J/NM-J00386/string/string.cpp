#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,w;
    string s;
    char a;
    cin>>n;
    
    long long x=0;
    for(int i=0;i<n;i++)
    {
    	cin>>w>>a;
    	for(int i=0;i<w;i++)
    	{
    		s=s+a;
		}
	}
	string s1=s;
	for(int i=0;i<s1.size()/2;i++)
	{
		s1[i]=s1[s.size()-i-1];
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s1[i])
		{
			x++;
		}
	}
	cout<<x;
    return 0;
}
