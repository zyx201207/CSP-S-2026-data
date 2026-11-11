#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
struct qjj{
	int cs;
	char zf;
}str[200005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>str[i].cs>>str[i].zf;
	int i=1,j=n;
	while(i<=j)
	{
		if(str[i].zf!=str[j].zf||str[i].cs!=str[j].cs)
		{
			if(str[i].zf!=str[j].zf)
				ans+=min(str[i].cs,str[j].cs);
			if(str[i].cs>str[j].cs)
			{
				str[i].cs-=str[j].cs;
				j--;
			}	
			else if(str[i].cs<str[j].cs)
			{
				str[j].cs-=str[i].cs;
				i++;
			}	
			else if(str[i].cs==str[j].cs)
				i++,j--;
		}
		else
		{
			i++;
			j--;
		}
//		cout<<ans<<'\n';
	}
	cout<<ans;
	return 0;
}
/*
5
2 a
1 c
3 b
3 c
2 d
*/