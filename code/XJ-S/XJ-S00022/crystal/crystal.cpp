#include<bits/stdc++.h>
using namespace std;
int n;long long a[500005],s[500005],m,maxn=1;
bool f;
long long last;
void search(int step,long long x,long long cnt,int step0)
{
	if(x==0||s[step0]-s[step-1]>x||step==1)
	{
		last=s[step0]-s[step-1];
		if(step==1)f=1;
		maxn=max(maxn,cnt);
		return;
	}
	search(step-1,x-s[step0]+s[step-1],cnt+1,step0);
}
bool cmp(long long x,long long y)
{
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<n;i++)
	{
	   a[i]=a[i+1]-a[i];
	}	
	for(int i=2;i<=n;i++)
	{
	 s[i]=a[i-1]+s[i-1];
	}
	for(int i=n;i>0;i--)
	{
		if(!f)search(i,m,1,i); 
	}
	cout<<maxn;
	return 0;
 } 
