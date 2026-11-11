//陈诗韵 西安翱翔中学 SN-J00650 
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll ans;
int a[200005];
char c[200005]; 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cin>>c[i];
	}
	int fst=1,lst=n;
	while(fst<lst)
	{
		if(a[fst]==a[lst]&&c[fst]==c[lst])
		{
			fst++;
			lst--;
		}
		else if(a[fst]==a[lst]&&c[fst]!=c[lst])
		{
			ans+=a[fst];
			fst++;
			lst--;
		}
		else if(a[fst]>a[lst])
		{
			if(c[fst]!=c[lst])ans+=a[lst];
			a[fst]-=a[lst];
			lst--;
		}
		else if(a[lst]>a[fst])
		{
			if(c[fst]!=c[lst])ans+=a[fst];
			a[lst]-=a[fst];
			fst++;
		}
	} 
	printf("%lld",ans);
	return 0;
}
