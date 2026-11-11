#include<bits/stdc++.h>
using namespace std;
long long n,x,l[200005],r[200005],i,h,t,len,cd[200005],ans=0;
char zf[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>cd[i]>>zf[i];
		l[i]=r[i-1]+1;
		r[i]=r[i-1]+cd[i];
	}
	h=1,t=n;
	while(h<t)
	{
		if(cd[h]>=cd[t])
		{
			if(zf[h]!=zf[t])ans+=cd[t];
			cd[h]-=cd[t];
			t--;
		}
		else
		{
			if(zf[h]!=zf[t])ans+=cd[h];
			cd[t]-=cd[h];
			h++;
		}
	}
	cout<<ans;
	return 0;
}
