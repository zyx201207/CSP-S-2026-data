#include<bits/stdc++.h>
using namespace std;
int n,b[200005];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++) s+=c;
	}
	int ans=0;
	for(int i=1;i<=n/2;i++)
		if(s[i]!=s[n-i+1]) ans++;
	cout<<ans;
	return 0;
}
