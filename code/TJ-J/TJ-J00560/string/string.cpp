#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int n;
	cin>>n;
	int l=0;
	int ans=0;
	string s;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		char c;
		cin>>c;
		for(int j=1;j<=a;j++) 
		{
			s+=c;
			l++;
		}
		
	}
	int b=l/2;
    for(int i=1;i<=b;i++)
    {
    	if(s[i]!=s[l-i+1]) 
		{
			ans++;
		}
	}
	cout<<ans-1;
	return 0;
 } 
