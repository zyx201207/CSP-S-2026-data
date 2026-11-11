#include<bits/stdc++.h>
using namespace std;
int a[200009];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		char c;
		cin>>c;
		for(int j=1;j<=a[i];j++)
			s+=c;
	}
	string d=s;
	int ans=0;
	reverse(d.begin(),d.end());
	for(int i=0;i<s.size()/2;i++)
		if(s[i]!=d[i])
			ans++;
	cout<<ans;
	return 0;
}
