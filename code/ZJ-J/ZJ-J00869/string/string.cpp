#include<bits/stdc++.h>
using namespace std;
int a[200010],n;
char c[200010];
long long lpos=1,rpos,ans;
void read(char &c)
{
	c=getchar();
	while(c<'a'||c>'z') c=getchar();
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		read(c[i]);
		rpos+=a[i];
	}
	int lblock=1,rblock=n;
	while(lpos<rpos)
	{
		int tmp=min(a[lblock],a[rblock]);
		if(c[lblock]!=c[rblock]) ans+=tmp;
		lpos+=tmp;
		rpos-=tmp;
		a[lblock]-=tmp;
		a[rblock]-=tmp;
		if(a[lblock]==0) lblock++;
		if(a[rblock]==0) rblock--;
	}
	printf("%lld",ans);
	return 0;
}
//十年OI一场空，不开long long见祖宗。long long渡江洒江郊，高者AC长林梢，下者CE沉塘坳。 
