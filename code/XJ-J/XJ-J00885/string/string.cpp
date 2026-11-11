#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
long long a[MAXN];
string s[MAXN];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,k,ans=0;
	cin>>n;
	for(long long i=1;i<=n;++i)
	{
		cin>>a[i]>>s[i];
	}
	long long i=1,j=n,t=0;
	long long cnt1=a[1],cnt2=a[n];
	while(i<j)
	{
		if(s[i]!=s[j])
		{
			t=min(cnt1,cnt2);
			cnt1-=t;cnt2-=t;
			ans+=t;
		}
		if(s[i]==s[j])
		{
			t=min(cnt1,cnt2);
			cnt1-=t;cnt2-=t;
		}
		if(cnt2==0)
		{
			j--;
			cnt2+=a[j];
		}
		if(cnt1==0)
		{
			i++;
			cnt1+=a[i];
		}
	}
	cout<<ans;
	return 0;
}