#include<bits/stdC++.h>
#define int long long
using namespace std;
const int maxN=5e5+10;
int read()
{
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
int tt,tot=-1e12-3,n,m,a[maxN];
int cAp(int mid)
{
	int sum=0;tt=0;
	for(int i=1;a[i]<=mid;i++)
	{
		sum+=mid-a[i];
		tt++;
//		cout<<"  i="<<i<<" a[i]="<<a[i]<<endl;
	}
//	cout<<"    sum="<<sum<<" tt="<<tt<<endl;
	if(sum<=m) return sum;
	else return -1;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1);//¶þ·Ö 
	int l=a[1],r=a[n];
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		int cap=cAp(mid);
//		cout<<" mid="<<mid<<endl;
		if(cap==-1) r=mid-1;
		else l=mid,tot=max(tot,tt);
//		cout<<"l="<<l<<" r="<<r<<" cAp="<<cap<<" tot="<<tot<<endl;
	}
	cout<<tot<<endl;
	return 0;
}
