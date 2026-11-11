#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m;
const int N=5e5+7;
ll a[N],d[N],pre[N]; 

ll read()
{
	char ch=getchar();
	ll res=0,f=1;
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*f;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n=read(),m=read();
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(i>=2) d[i]=a[i]-a[i-1];
		pre[i]=pre[i-1]+d[i];
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<"i="<<i<<" "<<d[i]<<" "<<pre[i]<<"\n";
//	}
	ll i=1,j=1,ans=0,len,cnt=0;
	while(i<=j&&j<=n)
	{
		len=j-i+1;
//		cout<<i<<" "<<j<<" "<<len<<" "<<cnt<<"\n";
		if(cnt<=m)
		{
			ans=max(ans,len);
			j++;
			cnt+=d[j]*len;
		}
		else
		{
			i++;
			cnt-=pre[j]-pre[i-1];
		}
	}
	cout<<ans<<"\n";
	return 0;
}
