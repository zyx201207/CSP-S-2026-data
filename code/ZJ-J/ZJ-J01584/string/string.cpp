/*#include<bits/stdc++.h>
using namespace std;
char s[10000010];
int n;
long long pos=0;
long long check()
{
	long long ans=0;
	for(int i=1;i<=pos/2;i++)
	{
		if(s[i]!=s[pos-i+1])
			ans++;
	}
	return ans;
}
int main()
{
	freopen("string3.in","r",stdin);
	freopen("string3.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int cur;
		scanf("%d ",&cur);
		char c;
		scanf("%c",&c);
		for(int j=1;j<=cur;j++)
		{
			s[pos+j]=c;
		}
		pos+=cur;
	}
	printf("%lld",check());
	return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char c[200010];
int len=0;
int main()
{
	freopen("string5.in","r",stdin);
	freopen("string5.out","w",stdout);
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d ",&a[i]);
		scanf("%c",&c[i]);
		len+=a[i];
	}
	int l=1,r=1;
	int lb=1,rb=n;
	long long ans=0;
	while(lb<=rb)
	{
		if(c[lb]!=c[rb])
			ans++;
		l++;
		if(l>a[lb])
		{
			l=1;
			lb++;
		}
		r++;
		if(r>a[rb])
		{
			rb--;
			r=1;
		}
	}
	printf("%lld",ans);
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010];
char c[200010];
long long len=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld ",&a[i]);
		scanf("%c",&c[i]);
		len+=a[i];
	}
	int ln=a[1],rn=a[n];
	int lb=1,rb=n;
	char lc=c[1],rc=c[n];
	long long ans=0;
	while(lb<=rb)
	{
		int samm=min(ln,rn);
		if(lc!=rc)
			ans+=samm;
		if(ln>rn)
		{
			ln-=samm;
			rb--;
			rn=a[rb];
			rc=c[rb];
		}
		else if(rn>ln)
		{
			rn-=samm;
			lb++;
			ln=a[lb];
			lc=c[lb];
		}
		else 
		{
			lb++;
			rb--;
			ln=a[lb];
			lc=c[lb];
			rn=a[rb];
			rc=c[rb];
		}
	}
	printf("%lld",ans);
	return 0;
}