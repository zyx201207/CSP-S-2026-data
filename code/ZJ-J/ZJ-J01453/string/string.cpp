#include<bits/stdc++.h>
using namespace std;
int gcda,a[200005],n,cnt=1,ans;
string s;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(i==1) gcda=a[i];
		else gcda=__gcd(gcda,a[i]);
	}
	for(int i=1;i<=n;i++) a[i]/=gcda;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
			s+=c[i];
	}
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-i-1])
		{
			ans++;
//			cout<<i<<" "<<s.size()-i-1<<" "<<s[i]<<" "<<s[s.size()-i-1]<<"\n";
		}
	}
	cout<<(long long)ans*gcda;
	return 0;
}

