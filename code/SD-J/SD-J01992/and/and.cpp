#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200010];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m,maxa=-1,maxb=-1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),maxa=max(maxa,a[i]);
	sort(a+1,a+n+1,cmp);
	ll s=a[1];
	if(m==1) cout<<s;
	else if(m==n) 
	{
		for(int i=2;i<=n;i++) s&=a[i];
		cout<<s;	
	} 
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				int b=a[i]&a[j];
				if(b>maxb) maxb=b;
			}
		cout<<maxb;	
	}
	if(maxa<4)
	{
		int e=0,b=0,c=0,d=0;
		for(int i=1;i<-n;i++) 
		{
			if(a[i]==0) b++;
			if(a[i]==1) c++;
			if(a[i]==2) d++;
			if(a[i]==3) e++;
		}
		if(m<=e) cout<<3;
		else if(m>e && m<=e+d) cout<<2;
		else if(m>e+d && m<=e+d+c) cout<<1;
		else cout<<0;
	}
	else cout<<a[m];
	return 0;
}
