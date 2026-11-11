#include<bits/stdc++.h>
using namespace std;
int n;
string s[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		string y;
		cin>>x>>y;
		for(int j=1;j<=x;j++)
		    s[i]=s+y;
	}
	int L=0,R=s.size()-1,ans=0;
	for(int i=1;i<=n/2;i++)
	{
		if(s[L]!=s[R]) ans++;
		L++;
		R--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
