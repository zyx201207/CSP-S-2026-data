#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int a[N];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	
	if(n==2)
	{
		int aa,bb;
		string ss1,ss2;
		
		cin>>aa>>ss1>>bb>>ss2;
		if(ss1!=ss2)
		{
			cout<<min(aa,bb);
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	
	string s,c,cc;
	bool same=1;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c;
		
		if(i!=1&&c!=cc)
		{
			same=0;
		}

		cc=c;
		
		for(int j=1;j<=a[i];j++)
		{
			s+=c;
		}
	}
	
	if(same)
	{
		cout<<0;
		return 0;
	}
	
	int ans=0;
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-1-i])
		{
			ans++;
		}
	}
	
	cout<<ans;
	return 0;
}
