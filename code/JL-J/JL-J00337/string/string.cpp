#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int n,a[200001],maxa=0;
char s[200001];
char S[200001];
long long L,l,r,haf,ans;
void bl()
{
	int tot=0;ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=a[i];j++)
				S[++tot]=s[i];
	for(int i=1;i<=tot/2;i++)
		if(S[i]!=S[tot-i+1])
			ans++;
	printf("%lld",ans);
	exit(0);
}		
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&a[i],&s[i]);
		L+=a[i];
		maxa=maxa>a[i]?maxa:a[i];
	}
	if(n*maxa<=3e8&&L/2<=3e8)
		bl();
	haf=L/2,l=0,r=0;
	for(int i=1;i<=n;i++)
	{
		l+=a[i],r+=a[n-i+1];
		if(l>haf||r>haf)
			break;
		if(l<r)
			
		if(s[i]!=s[n-i+1])
			ans+=abs(a[i]-a[n-i+1]);
	}
	printf("%lld",ans);
	return 0;
}

