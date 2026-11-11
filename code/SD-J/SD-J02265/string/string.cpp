#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500005],m,t,x=0,y=0,ans=0,tmp=0;//变通一下，考虑修改a,s 
char s[500005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		m+=a[i];
	}
	t=m/2;
	x=1;
	y=n;
	while(t>0) 
	{
		tmp=min(t,min(a[x],a[y]));
		a[x]-=tmp;
		a[y]-=tmp;
		t-=tmp;
		if(s[x]!=s[y])
		{
			ans+=tmp; 
		}
		if(a[x]==0)x++;
		if(a[y]==0)y--;
	}
	cout<<ans<<endl;
	return 0;
}
