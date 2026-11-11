#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace IO
{
	char buf[1<<16],*p1,*p2,ibuf;
	#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,sizeof(buf),stdin)),p1==p2?EOF:*p1++)
	int rd(int x=0,int f=1)
	{
		for(;!isdigit(ibuf);ibuf=getchar())if(ibuf=='-')f=-1;
		for(;isdigit(ibuf);ibuf=getchar())x=x*10+(ibuf^48);
			return x*f;
	}
}
using IO::rd;
int a[500050];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=rd(),m=rd();
	for(int i=0;i<n;i++)a[i]=rd();
	sort(a,a+n);
	int p=0;int ans=0;
	for(int i=0;i<n;i++)
	{
		if(i)m-=(i-p)*(a[i]-a[i-1]);
		while(m<0)m+=a[i]-a[p++];
		ans=max(ans,i-p+1);
	}
	cout<<ans<<endl;
}