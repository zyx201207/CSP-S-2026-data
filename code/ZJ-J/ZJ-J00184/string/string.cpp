//shuaiyuchenbianxie
#include<bits/stdc++.h>
using namespace std;
long long n,ans,ii=1,q[200500],mod=0;
char s[200005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char y;
		cin>>q[i]>>y;
		for(int j=1;j<=q[i];j++)
		{
			s[ii++]=y;
		}
	}
	long long l=1,r=ii-1;
	while(l<=r)
	{
		if(s[l]!=s[r])ans+++;
		l++,r--;
	}
	cout<<max(mod,ans);
	return 0;
}
