#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,a;
	char c;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++) s+=c;
	}
	int ans=0,l=0,r=s.size()-1;
	for(;l<=r;l++,r--) if(s[l]!=s[r]) ans++;
	cout<<ans;
	return 0;
}