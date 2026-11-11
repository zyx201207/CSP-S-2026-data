#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int cnt,a[N],b[N],s[N],n,a1[N],a2[N],b1[N],b2[N],s1[N],s2[N],c[N],d[N];
signed main()
{
 	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
 	ios::sync_with_stdio(0);
 	cin.tie(0);
 	cout.tie(0);
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>a[i]>>ch;
		b[i]=ch-'a'+1;
		cnt+=a[i];
		s[i]=s[i-1]+a[i];
	}
	int fl=0,m1=0,m2=0;
	for(int i=1;i<=n;i++)
	{
		if(!fl&&s[i]>cnt/2)
		{
			fl=1;
			a1[++m1]=cnt/2-s[i-1];
			a2[++m2]=s[i]-cnt/2;
			b1[m1]=b2[m2]=b[i];
			if(!a1[m1])
				m1--;
			if(cnt%2==1)
			{
				a2[m2]--;
				if(!a2[m2])
					m2--;
			}
		}
		else if(fl)
		{
			a2[++m2]=a[i];
			b2[m2]=b[i];
		}
		else
		{
			a1[++m1]=a[i];
			b1[m1]=b[i];
		}
	}
	for(int i=m2;i>=1;i--)
		c[i]=a2[m2-i+1],d[i]=b2[m2-i+1];
	for(int i=1;i<=m1;i++)	s1[i]=s1[i-1]+a1[i];
	for(int i=1;i<=m2;i++)	s2[i]=s2[i-1]+c[i];
	int t1=0,t2=0,ans=0,now=0;
	while(now<cnt/2)
	{
		if(now==s1[t1]&&now)
		{
			if(s1[t1+1]>=s2[t2])
			{
				if(b1[t1+1]!=d[t2])
					ans+=s2[t2]-now;
				now=s2[t2];
				t1++;
			}
			else
			{
				if(b1[t1+1]!=d[t2])
					ans+=s1[t1+1]-now;
				now=s1[t1+1];
				t1++;
			}
		}
		else
		{
			if(s1[t1]==s2[t2])
			{
				if(s1[t1+1]>=s2[t2+1])
				{
					if(b1[t1+1]!=d[t2+1])
						ans+=s2[t2+1]-now;
					now=s2[t2+1];
					t1++;t2++;
				}
				else
				{
					if(b1[t1+1]!=d[t2+1])
						ans+=s1[t1+1]-now;
					now=s1[t1+1];
					t1++;t2++;
				}
			}
			else if(s1[t1]>=s2[t2+1])
			{
				if(b1[t1]!=d[t2+1])
					ans+=s2[t2+1]-now;
				now=s2[t2+1];
				t2++;
			}
			else
			{
				if(b1[t1]!=d[t2+1])
					ans+=s1[t1]-now;
				now=s1[t1];
				t2++;
			}
		}
	}
	cout<<ans;
 	return 0;
}
