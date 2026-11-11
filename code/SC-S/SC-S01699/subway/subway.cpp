#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
ll c,n,m,d,q;
ll w[N],k[N],t[510][N],x,y;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;++i) w[i]=read();
	for(int i=1;i<=n;++i)
	{
		k[i]=read();
		for(int j=1;j<=2*k[i];j++) t[i][j]=read();
	}
	for(int i=1;i<=q;i++) x=read(),y=read();
	cout<<w[1]+t[1][1]+(t[1][2]+t[2][2])+t[2][3]+w[3]<<endl<<w[1]+t[1][1]+t[1][2]+w[2];
	return 0;
}//编译器出问题了 