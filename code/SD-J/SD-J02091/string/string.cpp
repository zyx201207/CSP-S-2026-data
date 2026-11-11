#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	#define int  unsigned long long 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,a,cnt=0;
	char c;
	string s1,s2;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s1+=c;
		}
	}
	cout<<s1<<endl;
	for(int i=s1.size()-1;i>=0;i--)
	{
		s2+=s1[i];
	}
	cout<<s2<<endl;
	for(int i=0;i<s1.size();i++)
	{
		if(s2[i]!=s1[i])
		{
			cnt++;
		}	
	}
	cout<<cnt/2;
	return 0;
}	
