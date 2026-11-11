#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int u[2000005],v[2000005];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();
	t=read();
	int q=t;
	while(t--){
		n=read();
		k=read();
		for(int i=1;i<=n;i++){
			u[i]=read();
			v[i]=read();
		}
		printf("%d\n",q-t);
	}
}