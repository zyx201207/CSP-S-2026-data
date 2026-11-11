#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,A[N],B[N],nxt[N];
int ans[N];
int read()
{
	int x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9')
		x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x;
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		A[i]=read();
	for(int i=n;i>=1;i--)
	{
		if(B[A[i]])
			nxt[i]=B[A[i]]+1;
		else nxt[i]=i+1;
		if(!B[A[i]])
			B[A[i]]=i;
	}
	memset(B,0,sizeof(B));
	for(int i=1;i<=n;i++)
	{
		B[i]++;
		//printf("%d %d\n",i,B[i]);
		B[nxt[i]]+=B[i];
		ans[A[i]]+=B[i];
	}
	for(int i=1;i<=m;i++)
		printf("%lld ",ans[i]);
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1

71 1 126 6 3 23 16 1 9 19 3 8 6 1 3 87 9 2 223 2 226 9 10 3 20 2 4 3 59 6 25 3 12 3 1 3 3 1 2 404 2 33 31 25 34 17 5 173 4 325 125 3 178 27 11 4 6 303 11 5 5 399 39 9 3 6 129 319 3 249 5 261 2 1 2 4 8 2 30 1 4 10 7 3 1 83 12 36 62 1 2 6 2 7 88 134
71 1 126 6 3 23 16 1 9 19 3 8 6 1 3 87 9 2 223 2 226 9 10 3 20 2 4 3 59 6 25 3 12 3 1 3 3 1 2 404 2 33 31 25 34 17 5 173 4 325 125 3 178 27 11 4 6 303 11 5 5 399 39 9 3 6 129 319 3 249 5 261 2 1 2 4 8 2 30 1 4 10 7 3 1 83 12 36 62 1 2 6 2 7 88 134
*/
