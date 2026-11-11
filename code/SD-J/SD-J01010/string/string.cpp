#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;string s;long long ans=0,len=0;
long long a[N];char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];++j)
		{
			s+=c[i];
			++len;
		}
	}
	for(long long i=0;i<len/2;++i)
	{
		if(s[i]!=s[len-i-1]) ++ans;
	}
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}
