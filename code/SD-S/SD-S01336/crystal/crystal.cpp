#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	ll sum=0,l=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')l=-1;c=getchar();}
	while(isdigit(c)){sum=sum*10+c-'0';c=getchar();}
	return sum*l;
}
ll c[500100],qz[500100];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n=read(),m=read(),l=1,ans=0;
	for(ll i=1;i<=n;i++)c[i]=read();
	sort(c+1,c+1+n);
	for(ll i=1;i<=n;i++)
	{
		qz[i]=qz[i-1]+c[i];
		while(c[i]*(i-l+1)-(qz[i]-qz[l-1])>m)l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
