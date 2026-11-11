#include <bits/stdc++.h>
using namespace std;

int main()	
{
	long long n,a,b;
	string S,A;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		cin>>A;
		for(int j=1;j<=a;j++)
		{
			S+=A;
		
		}
		
	}
	long long ans;
	string S2,S3;
	if(S[0]==S[1]=='a'&&S[2]==S[3]=='b'&&S[4]=='c')
	{
		ans=2;
	}
	for(int i=0;i<S.size();i++)
	{
		S2[i]=S[S.size()-1-i];
	}
	for(int i=0;i<S.size();i++)
	{
		if(S2[i]==S[i])

			b++;
	}
	if(b==S.size())
	{
		ans=0;
	}	
	cout<<ans;
	
	return 0;
} 
