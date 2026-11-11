#include<bits/stdc++.h>
using namespace std;
const int slen=2e5+10;
long long a[slen];
char c[slen];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	long long last=0;
	long long ans=0;
	int now=1,tail=n;
	while(now<tail)
	{
		char node=c[now],dui=c[tail];
		if(node!=dui||a[now]!=a[tail])
		{
			long long s1=max(a[now],a[tail]),s2=min(a[now],a[tail]);
			if(node!=dui)	ans+=s2;
			last=s1-s2;//first is end
			if(a[tail]-a[now]>=0)
			{
				a[tail]-=a[now];now++;
				if(a[tail]==0)	tail--;
				continue;
			}
			tail--;now++;
			while(last>0)
			{
				int fuzai;
				if(c[tail]!=node)
				{
					fuzai=min(last,a[tail]);
				}
				if(last>a[tail])
				{
					last-=a[tail];
					a[tail]=0;
				}
				else
				{
					last=0;
					a[tail]-=last;
				}
				if(a[tail]==0)	tail--;
				ans+=fuzai;
			}
		}
	}
	cout<<ans;
	return 0;
}