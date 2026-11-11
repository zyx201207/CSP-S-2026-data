//郭骐领 西安市益新中学 SN-J00682
#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	string s="";
	while(t--)
	{
		int x;
		char y;
		cin>>x>>y;
		for(int i=1;i<=x;i++)
			s+=y;
	}
	int ans=0;
	for(int i=0,j=s.size()-1;i<=j;i++,j--)
	{
		if(s[i]!=s[j])
			ans++;
	}
	cout<<ans;
	return 0;
}
