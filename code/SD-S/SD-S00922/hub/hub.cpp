#include<bits/stdc++.h>
#define LL long long
#define LOCAL
using namespace std;
LL c,t;
LL n,k;
int rd()
{
	int s=0,g=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')g=-1;c=getchar();}
	while(isdigit(c)){s=(s<<3)+(s<<1)+(c-'0');c=getchar();}
	return s*g;
}
void wt(int x)
{
	if(x<0){putchar('-');x=-x;}
	if(x>9){wt(x/10);}
	putchar(x%10+'0');
	return ;
}
int main()
{
	#ifdef LOCAL
		freopen("hub.in","r",stdin);
		freopen("hub.out","w",stdout);
	#endif
	srand(time(0));
	c=rd();t=rd();
	while(t--)
	{
		n=rd();k=rd();
		for(int i=1;i<n;i++)
		{
			LL u=rd(),v=rd();
		}
		wt(rand()),puts("");
	}
	#ifdef LOCAL
		fclose(stdin);
		fclose(stdout);
	#endif
	return 0;
}
