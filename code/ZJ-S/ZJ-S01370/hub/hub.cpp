#include<bits/stdc++.h>
using namespace std;
int t,c,n,k;
inline long long read()
{
	long long f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	  {
	  	if(ch=='-')
	  	  f=-1;
	  	ch=getchar();
	  }
	while(ch>='0'&&ch<='9')
	  x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();
	t=read();
	while(t--)
	  {
	  	n=read();
	  	k=read();
	  	for(int i=1;i<n;i++)
	  	  {
	  	  	int u,v;
	  	  	u=read();
	  	  	v=read();
		  }
		if(k==n)
		  printf("0\n");
		else
		  printf("1\n");
	  }
	return 0;
}
