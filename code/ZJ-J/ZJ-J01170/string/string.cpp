#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	vector<int>a1,a2;
	vector<char>c1,c2;
	int a[n+1];
	char c[n+1];
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++)a1.push_back(a[i]),c1.push_back(c[i]); 
	for(int i=n;i>=1;i--)a2.push_back(a[i]),c2.push_back(c[i]);
	int l1,l2;
	char s1,s2;
	while(!a1.empty()&&!a2.empty())
	{
		l1=a1.back(),l2=a2.back();
		s1=c1.back(),s2=c2.back();
		if(l1==l2)
		{
			if(s1!=s2)ans+=l1;
			a1.pop_back(),c1.pop_back();
			a2.pop_back(),c2.pop_back();
		}
		if(l1<l2)
		{
			if(s1!=s2)ans+=l1;
			a2.back()-=a1.back();
			a1.pop_back(),c1.pop_back();
		}
		if(l1>l2)
		{
			if(s1!=s2)ans+=l2;
			a1.back()-=a2.back();
			a2.pop_back(),c2.pop_back();
		}
	}
	cout<<ans/2;
	return 0;
}
