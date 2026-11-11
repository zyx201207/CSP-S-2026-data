#include<bits/stdc++.h>
using namespace std;
int n;
long long sum=0;
int a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&a[i],&c[i]);
	}
	int num1=1,num2=n;
	while(num1<num2)
	{
		int l=min(a[num1],a[num2]);
		if(c[num1]!=c[num2])
		{
			sum+=l;
		}
		a[num1]-=l,a[num2]-=l;
		if(a[num1]==0) num1++;
		if(a[num2]==0) num2--;
	}
	printf("%lld",sum);
	return 0;
}
