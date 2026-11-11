#include<bits/stdc++.h>
using namespace std;
struct qwe{
	long long a,b;
};
qwe t[500005];
bool cmp(qwe x,qwe y)
{
	return x.b<y.b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,p=0;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&t[i].a);
		p += t[i].a;
	}
	p = p/n;
	for(int i=1;i<=n;i++)
	{
		t[i].b=abs(p-t[i].a);
	}
	sort(t+1,t+n+1,cmp);
	long long sum=1,bg=t[1].a;
	for(int i=2;i<=n;i++)
	{
		if(t[i].a<=bg)
		{
			if(t[i].b>m)
			{
				break;
			}
			else
			{
				m-=t[i].b;
				sum++;
			}
		}
	}
	printf("%lld",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
