#include<bits/stdc++.h>
#define u unsigned
#define ll long long
#define ull u ll
using namespace std;
u c,T,n,ans,Cnt;
ull d,vis[2000010];
void F(u from,u to,u step)
{
	if(step==0){if(from==to){Cnt++;}return;}
	for(u i=from+1;(i<=to)&&(vis[i]-vis[from]<=d);i++)
	{
		F(i,to,step-1);
	}
}
inline void f(const int& x)
{
	for(u i=x,cnt=1;i<=n;)
	{
		u T=i+1;
		while((T<=n)&&(vis[T]-vis[i]<=d)){T++;}
		for(u k=i;k<T;k++)
		{
			Cnt=0;
			F(x,k,cnt);
			if(Cnt==2){ans++;}
		}
		cnt++;
		i=T;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%u%u",&c,&T);
	while(T--)
	{
		scanf("%u%llu",&n,&d);
		ans=0;
		for(u i=1;i<=n;i++){scanf("%llu",&vis[i]);}
		for(u i=1;i<n;i++){f(i);}
		printf("%u\n",ans);
	}
	return 0;
}
/*
*/
