#include<bits/stdc++.h>
using namespace std;
string s;
int n;
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		char c;
		scanf("%d %c",&x,&c);
		for(int i=1;i<=x;i++) s+=c;
	}
	int l=s.size();
	for(int i=0;i<l/2;i++)
	{
		if(s[i]!=s[l-1-i]) ans++;
	}
	printf("%lld",ans);
	return 0;
}