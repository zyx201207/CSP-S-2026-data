#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
inline int read()
{
	int sum=0,f=1;
	char c=getchar();
	while(!isdigit(c)) {if(c=='-') f=-f;c=getchar();}
	while(isdigit(c)) {sum=((sum<<3)+(sum<<1))+c-48;c=getchar();}
	return sum*f;
}
int a[N],pos[N],ans[N],cnt[N],pl[N],n,m;
bool checkA()
{
	for(int i=2;i<=n;i++) {if(a[i]<a[i-1]) return 0;}
	return 1;
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	if(n<=500)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(pos[a[j]])
				{
					for(int k=1;k<=m;k++) if(pos[k]>pos[a[j]]) pos[k]=0;
				}
				else pos[a[j]]=j;
			}
			for(int j=1;j<=m;j++) {if(pos[j]) ans[j]++;}
			for(int j=1;j<=m;j++) {pos[j]=0;}
		}
		for(int i=1;i<=m;i++) {cout<<ans[i]<<" ";} return 0;
	}
	if(n<=5000 && checkA())
	{
		for(int i=1;i<=n;i++) {cnt[a[i]]++;}
		for(int i=1;i<=n;i++)
		{
			cnt[a[i-1]]--;
			for(int i=1;i<=m;i++) pl[i]=0;
			for(int j=i;j<=n;j++)
			{
				if(cnt[a[j]] && !pl[a[j]]) ans[a[j]]++,pl[a[j]]=1;
			}
		}
		for(int i=1;i<=m;i++) {cout<<ans[i]<<" ";} return 0;
	}
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

4 3
1 2 2 3
*/