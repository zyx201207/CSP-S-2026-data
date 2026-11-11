#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n;
int a[N];
char c[N];
int cnt;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		scanf(" %c",c+i);
	}
	int head=1,tail=n;
	while(head<tail)
	{
		if(c[head]==c[tail])
		{
			if(a[head]>a[tail])
				a[head]-=a[tail--];
			else if(a[head]<a[tail])
				a[tail]-=a[head++];
			else 
				head++,tail--;
		}
		else if(c[head]!=c[tail])
		{
			if(a[head]>a[tail])
			{
				a[head]-=a[tail];
				cnt+=a[tail];
				tail--;
			}
			else if(a[head]<a[tail])
			{
				a[tail]-=a[head];
				cnt+=a[head];
				head++;
			}
			else 
			{
				cnt+=a[head];
				head++,tail--;
			}
		}
	}
	printf("%lld",cnt);
	return 0;
} 
