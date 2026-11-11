#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a,d;
}; 
node s[500005];
bool cmp(node x,node y)
{
	return x.d<y.d;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,i;
	double sum;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>s[i].a;
		sum+=s[i].a;
	}
	long long mj;
	double Min=sum,ans=0;
	sum/=n;
	for(i=1;i<=n;i++)
	{
		s[i].d=int(abs(s[i].a-sum));
		if(Min>s[i].d)
		{
			Min=s[i].d;
			mj=s[i].a;
		}
	}
	sort(s,s+n+1,cmp);
	for(i=1;i<=n;i++)
	{
		if(s[i].a==mj) ans++;
		else if(ans>0) break;
	}
	long long x=0;
	while(m>=0)
	{
		if(m-abs(s[++x].a-mj)>=0)
		{
			ans++;
			m=m-abs(s[++x].a-mj);
		}
		else break;
	}
	cout<<ans;
	return 0;
} 
