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
ll c[2001000],qz[2001000],s[2001000],cnt;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll id=read(),t=read();
	while(t--)
	{
		ll n=read(),d=read();
		for(ll i=1;i<=n;i++)c[i]=read();
		for(ll i=n;i>1;i--)qz[i]=c[i]-c[1],c[i]=c[i]-c[i-1];
		qz[1]=c[1]=0;
		if(id==11||id==12)
		{
			if(n==1)cout<<"0\n";
			else
			{
				ll ci=d/c[2]*2-1;
				if(ci==1||ci==-1)cout<<"0\n";
				else cout<<max(0ll,n-ci)<<"\n";
			}
			continue;
		}
		ll ans=0;
		for(ll i=1;i<=n;i++)
		{
			cnt=0;
			ll fl=0;
			s[0]=i;
			while(s[cnt]!=n)
			{
				cnt++;
				s[cnt]=upper_bound(qz+1,qz+1+n,qz[s[cnt-1]]+d)-qz-1;
				if(s[cnt]==s[cnt-1])break;
				if(cnt==1)continue;
				if(!fl)
				{ 
					if(s[cnt-1]-s[cnt-2]!=1&&(cnt<=2||qz[s[cnt-1]-1]-qz[s[cnt-2]-1]>d))
					{
						ll l=upper_bound(qz+1,qz+1+n,qz[s[cnt-1]-2]+d)-qz;
						ll r=upper_bound(qz+1,qz+1+n,qz[s[cnt-1]-1]+d)-qz-1;
						ans+=max(0ll,r-l+1);
					}
				}
				else
				{
					ll l=upper_bound(qz+1,qz+1+n,qz[s[cnt-1]-1]+d)-qz;
					ans+=s[cnt]-l+1;
				}
				if(qz[s[cnt]]-qz[s[cnt-1]-1]<=d)
				{
					if(fl)break;
					fl=1;
					if(qz[s[cnt]]-qz[s[cnt-1]-2]<=d||(cnt>2&&qz[s[cnt-1]-1]-qz[s[cnt-2]-1]<=d))break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
