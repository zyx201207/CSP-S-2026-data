#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
int andn(int x,int y)
{
	int a=max(x,y),b=min(x,y),ans=0,s=-1,t;
	while(true)
	{
		s++;
		int tempa=a%2,tempb=b%2;
		if(tempa==1&&tempb==1) t=1;
		else t=0;
		ans+=t*pow(2,s);
		a/=2;b/=2;
		if(!b) break;
	}
	return ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==n)
	{
		ans=andn(a[1],a[2]);
		for(int i=2;i<=n;i++) ans=andn(ans,a[i]);
		cout<<ans; return 0;
	}
	if(m==1)
	{
		cout<<m;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,andn(a[i],a[j]));
			}
		cout<<ans;
		return 0;
	}
}
