#include<bits/stdc++.h>
using namespace std;
int m,n,ans;
int x2[35],y2[35],r2[35],cx2,cy2,cr2,sum;
long long a[100005];
int and1(int x,int y)
{
	memset(x2,0,sizeof(x2));
	memset(y2,0,sizeof(y2));
	memset(y2,0,sizeof(r2));
	sum=0;
	for(int i=1;i>=0;i++)
	{
		if(x==0) break;cx2=i;
		x2[i]=x%2;
		x/=2;
    }
	for(int i=1;i>=0;i++)
	{
		if(y==0) break;cy2=i;cr2=min(cx2,cy2);
		y2[i]=y%2;
		y/=2;
		if(y2[i]==x2[i]) r2[i]=y2[i];
    }
	for(int i=1;i<=cr2;i++) 
	{
		int p=r2[i];
		if(i==1) sum+=p;
		else 
		{
			p=(p<<i-1);
			sum+=p;
		}
	}
	return sum;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=and1(a[n],a[n-1]);
	for(int i=n-2;i>=n-m+1;i--) ans=and1(ans,a[i]);
	cout<<ans;
	return 0;
} 
