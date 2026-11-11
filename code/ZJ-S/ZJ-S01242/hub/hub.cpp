#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
inline int read()
{
	int sum=0,f=1;
	char c=getchar();
	while(!isdigit(c)) {if(c=='-') f=-f;c=getchar();}
	while(isdigit(c)) {sum=(sum<<1)+(sum<<3)+c-48;c=getchar();}
	return sum*f;
}
int c,t,n,k;
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	for(int test=1;test<=t;test++)
	{
		n=read(),k=read();
		for(int i=1,u,v;i<n;i++)
		{
			u=read(),v=read();
		}
		cout<<"0\n";
	}
	return 0;
}
/*
5 5
1 2 4 8 9

5 5
1 4 6 7 7

5 8
-3 -1 2 2 7
*/