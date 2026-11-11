#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[200010];
long long c[200010];
long long rew[200010],p[200010];
long long sum;
long long pre[200010][30];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	for(int i=1;i<=n;i++){
		rew[i]=rew[i-1]+a[i];
	}
	for(int i=n;i>=1;i--)
	{
		p[i]=p[i+1]+a[i];
	for(int j=0;j<26;j++)
	{
		pre[i][j]+=pre[i+1][j]-a[i]*(c[i]-'a'==1);
	}
}
cout<<cnt;
	return 0;
}
