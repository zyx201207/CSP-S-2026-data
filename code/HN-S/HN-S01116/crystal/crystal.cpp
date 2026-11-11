#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll A=50015;
ll n,m;
ll  g;
ll  sum=0;
ll aj[A];
ll fh(ll f1[])
{
	int sun=0;
	int jk[A];
	for(int i=1;i<=n;i++) jk[i]=0;
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(f1[i]==f1[j])
			{
			jk[i]++;
			}
		}
	}

	for(int i=1;i<=n;i++) sun=max(jk[i]+1,sun);
	return sun;
}

int main()
{
	freopen("crystal.in" , "r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>aj[i];
	}
	
	ll dp=m;
	ll jkj=1;
	ll  p=fh(aj);
	if(fh(aj)==n) cout<<n;
	else{
	for(int i=1;i<=n;i++)
	{	dp = m;
		jkj=1;
		while(dp!=0&&m!=0&& jkj<=m)
		{
			aj[i]+=jkj;
			int dx=fh(aj);
			if(p<=dx)
			{
				p=dx;
				dp--;
			}
			else
			{
				aj[i]-=jkj;
				jkj+=1;
				dp--;
			}
		}	
	}cout<<p;
}
return 0;
}

