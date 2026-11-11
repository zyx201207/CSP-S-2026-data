#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	char c;
    	int x;
    	cin>>x>>s;
    	for(int i=1;i<=x;i++)
    		s+=c;
	}
	int len=s.size()-1,ans=0;
	for(int i=1;i<=len/2;i++)
	{
		if(s[i]!=s[n-i+1]) ans++;
	}
	cout<<ans;
} 
