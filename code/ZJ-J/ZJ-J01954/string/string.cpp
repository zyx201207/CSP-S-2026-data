#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int s,n,j,a[N],b[N];
char c[N];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	scanf("%d %c",&a[0],&c[0]);
	b[0]=a[0];
	s+=a[0];
	for(int i=1;i<n;i++)
	{
		scanf("%d %c",&a[i],&c[i]);
		b[i]=b[i-1]+a[i];
		s+=a[i];
	}
	s--;
	for(int i=0;i<=s/2;i++)
	{
		if(i>b[j])
			j++;
		if(c[j]!=c[s-j])
			ans++;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
