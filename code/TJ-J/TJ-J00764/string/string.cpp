#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const long long MAXN=2e8;
char s[MAXN];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long n;
	cin>>n;
	long long tot=0;
	for(long long i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		char c;
		cin>>c;
		for(long long j=1;j<=x;j++)
		{
			s[tot]=c;
			tot++;
		}
	}
	long long cnt=0;
	for(long long i=0;i<tot;i++)
	{
		if(s[i]!=s[tot-i-1])cnt++;
	}
	cout<<cnt/2;
	return 0;
}
