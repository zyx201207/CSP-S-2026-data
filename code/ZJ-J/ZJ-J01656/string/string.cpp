#include<bits/stdc++.h>
using namespace std;
int n,x[200010],cnt,Max;
long long sum;
char y[200010];
struct node
{
	int k;
	char p;
}a[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char s=' ';
	for(int i=1;i<=n;i++)
	{
		char rt;
		scanf("%d%c",&x[i],&rt);
		while(rt==' ') scanf("%c",&rt);
		y[i]=rt;
		if(rt==s) a[cnt].k+=x[i];
		  else
		  {
		  	a[++cnt].k=x[i];
		  	a[cnt].p=rt;
		  }
		sum+=x[i];
		Max=max(Max,x[i]);
		s=rt;
	}
	if(1ll*Max*n<=100000000)
	{
		string st="";
		for(int i=1;i<=n;i++)
		{
			while(x[i]--) st+=y[i];
		}
		int bos=0;
		for(int i=0;i<sum/2;i++)
		  if(st[i]!=st[sum-i]) bos++;
		cout<<bos<<endl;
		return 0;
	}
	int m=sum/2,ans=0;
	for(int i=1;i<=cnt;i++)
	  if(ans+a[i].k>=m)
	  {
	  	ans=i;
	  	break;
	  }
	  else ans+=a[i].k;
	long long l=0,r=sum+1,ts=0;
	int pl=1,pr=cnt;
	while(l+1<r&&pl<pr)
	{
		if(l>sum-r+1)
		{
			while(sum-r+1<l&&pr>pl)
			{
				r-=a[pr].k;
				if(r<=m+1) r=m+1;
				pr--;
			}
			if(a[pl-1].p!=a[pr].p) ts+=max(sum-r+1-l,0ll);
		} 
		else
		{
			while(l<=sum-r+1&&pr>pl)
			{
				l+=a[pl].k;
				if(l>=m) l=m;
				pl++;
			}
			if(a[pl].p!=a[pr+1].p) ts+=max(l-sum+r-1,0ll);
		}
	} 
	cout<<ts<<endl;
	return 0;
}
