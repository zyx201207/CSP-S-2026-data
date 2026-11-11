#include<bits/stdc++.h>
#define int long long
using namespace std;
int pos1,pos2,ans;
int n,a[1000001];
char s[1000001];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>s[i];
	pos2=n;
	while(pos1<pos2)
	{
		if(a[pos1]==0)pos1++;
		if(a[pos2]==0)pos2--;
		if(pos1>=pos2)break;
		int minn=min(a[pos1],a[pos2]);
		a[pos1]-=minn,a[pos2]-=minn;
		if(s[pos1]!=s[pos2])ans+=minn;
	}
	cout<<ans;
	return 0;
}