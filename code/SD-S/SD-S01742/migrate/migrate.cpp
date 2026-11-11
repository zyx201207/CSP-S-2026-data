#include<iostream>
#include<cstdio>
#include<utility>
#include<vector>
#define lint long long
using namespace std;
int s[2000005];
int s2[2000005];
int d[2000005];
int ans;
int l[2000005];
int c,n,p;
lint a[2000005],D;
void mn()
{
	cin>>n>>D;
	p=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		s[i]=i,s2[i]=i,d[i]=i;
		cin>>a[i];
		while(a[i]-a[p]>D) p++;
		l[i]=p;
	}//cerr<<"???";
	for(int i=1;i<=n;i++)
	{
		int j=i;
		/*for(int j=i;j>0;j--)
		{
			while(L>j&&l[L]-L) L=l[L];
			if(L==j&&s[i]==j)
			{
				if(s2[i]==j+1&&j<=i-2) for(int k=l[j+1];k<min(j,l[j+2]);k++) d[i]=min(d[i],k),ans++;
				for(int k=l[j];k<(j+1<=i?l[j+1]:i);k++)// s[i]=min(s[i],k);
				{
					if(k<s[i])
					{
						s2[i]=s[i];
						s[i]=k;
					}
					else if(k<s2[i]) s2[i]=k;
				}
			}
			else if(L==j&&d[i]==j) for(int k=l[j];k<(j+1<=i?l[j+1]:i);k++) d[i]=min(d[i],k),ans++;
		}*/
		while(l[j]-j)
		{
			if(s[i]==j)
			{
				if(s2[i]==j+1&&j<=i-2) for(int k=l[j+1];k<min(j,l[j+2]);k++) d[i]=min(d[i],k),ans++;
				for(int k=l[j];k<(j+1<=i?l[j+1]:i);k++)// s[i]=min(s[i],k);
				{
					if(k<s[i])
					{
						s2[i]=s[i];
						s[i]=k;
					}
					else if(k<s2[i]) s2[i]=k;
				}
			}
			else if(d[i]==j) for(int k=l[j];k<(j+1<=i?l[j+1]:i);k++) d[i]=min(d[i],k),ans++;
			else break;
			j=l[j];
		}
	}/*cerr<<"???";
	for(int i=1;i<=n;i++) cerr<<l[i]<<' ';
	cerr<<'\n';
	for(int i=1;i<=n;i++)
	{
		cerr<<i<<':';
		for(int j=1;j<i;j++) cerr<<s[i][j]<<' ';
		cerr<<'\n';
	}
	for(int i=1;i<=n;i++)
	{
		cerr<<i<<':';
		for(int j=1;j<i;j++) cerr<<d[i][j]<<' ';
		cerr<<'\n';
	}*/
	cout<<ans<<'\n';
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	cin>>c>>T;
	while(T--) mn();
	return 0;
}
