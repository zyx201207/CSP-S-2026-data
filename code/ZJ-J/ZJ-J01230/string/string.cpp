#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
inline int read()
{
	int sum=0,f=1;
	char c=getchar();
	while(!isdigit(c)) {if(c=='-') f=-f;c=getchar();}
	while(isdigit(c)) {sum=((sum<<3)+(sum<<1))+c-48;c=getchar();}
	return sum*f;
}
int a[N],n,cnt;
char c[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read(),c[i]=' ';
		while(c[i]==' ') c[i]=getchar();
	}
	for(int i=1,j=n,ni=0,nj=0,mn=0;i<=n;)
	{
		mn=min(a[j]-nj,a[i]-ni);
		if(c[i]!=c[j]) cnt+=mn;
		ni+=mn,nj+=mn;
		if(nj==a[j]) j--,nj=0;
		if(ni==a[i]) i++,ni=0;
		if(i>=j) break;
	}
	cout<<cnt;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/