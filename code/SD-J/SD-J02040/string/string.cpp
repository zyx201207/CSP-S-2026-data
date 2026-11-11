#include<bits/stdc++.h>
using namespace std;
struct sub
{
	int a;
	char c;
};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long ans=0;
	int n;
	cin>>n;
	sub s[200010];
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].c;
	}
	int l=1,r=n;
	while(l<r)
	{
		int t=min(s[l].a,s[r].a);
		s[l].a-=t;
		s[r].a-=t;
		if(s[l].c!=s[r].c) ans+=t;
		if(s[l].a==0) l++;
		if(s[r].a==0) r--;
	}
	cout<<ans;
	return 0;
}
