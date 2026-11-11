#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,A[N];
vector<int>R1,R2;
int read()
{
	int x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9')
		x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x;
}
void check(int x)
{
	for(int v:R1)
		if((v>>x)&1)
			R2.push_back(v);
	if(R2.size()>=m)
	{
		R1.clear();
		for(int v:R2)
			R1.push_back(v);
	}
	R2.clear();
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		A[i]=read(),
		R1.push_back(A[i]);
	for(int i=30;i>=0;i--)
		check(i);
	int ans=-1;
	for(int v:R1)
	{
		if(ans==-1) ans=v;
		else ans&=v;
	}
	printf("%d\n",ans);
	return 0;
}
