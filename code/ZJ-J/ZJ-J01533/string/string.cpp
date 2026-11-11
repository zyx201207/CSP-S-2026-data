#include<bits/stdc++.h>
using namespace std;
string s;
long long a,n,ans;
char c;
int main()
{
	freeopen("string.in","r",stdin);
	freeopen("string.out","w",stdout);
	cin>>n;
	while(n--)
	{
		cin>>a>>c;
		while(a--) s+=c;
	}
	int m=s.size()-1;
	for(int i=0;i<=m/2+1;i++)
	{
		if(s[i]!=s[m-i]) ans++,s[m-i]=s[i];
	}
	cout<<ans;
	return 0;
}
