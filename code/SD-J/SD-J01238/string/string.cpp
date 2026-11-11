#include<bits/stdc++.h>
using namespace std;
int n;
const int N=2e5+10;
long long len[N];
char s[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long x;
		char ss;
		cin>>x>>ss;
		s[i]=ss;
		len[i]=x;
	}
	long long cnt=0;
	int l=1,r=n;
	while(l<=r)
	{
		if(len[l]>len[r]&&s[l]!=s[r])
		{
			cnt+=len[r];
			len[l]-=len[r];
			r--;
		}
		if(len[r]>len[l]&&s[l]!=s[r])
		{
			cnt+=len[l];
			len[r]-=len[l];
			l++;
		}
		if(len[r]==len[l]&&s[l]!=s[r])
		{
			cnt+=len[l];
			r--;
			l++;
		}
		if(len[l]>len[r]&&s[l]==s[r])
		{
			len[l]-=len[r];
			r--;
		}
		if(len[r]>len[l]&&s[l]==s[r])
		{
			len[r]-=len[l];
			l++;
		}
		if(len[r]==len[l]&&s[l]==s[r])
		{
			r--;
			l++;
		}
	}
	cout<<cnt;
	return 0;
} 
