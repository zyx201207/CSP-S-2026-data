#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+5;
int n,a[N];
LL ans=0;
char c[N];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	
	int t1=1,t2=n;
	while(t1<t2)
	{
		if(c[t1]!=c[t2])
		{
			ans+=min(a[t1],a[t2]);
		}
		
		if(a[t1]>a[t2])
		{
			a[t1]-=a[t2];
			t2--;
		}
		else if(a[t1]<a[t2])
		{
			a[t2]-=a[t1];
			t1++;
		}
		else
		{
			t1++;
			t2--;
		}
		
	}
	
	printf("%lld",ans);
	return 0;
}
