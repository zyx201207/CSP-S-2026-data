#include<bits/stdc++.h>
using namespace std;
const int MA=200005;
#define int long long
int c,t,n,m,d,x[MA],ans,fa[MA];
bool is[MA],ca[MA][2];
int get(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y)
{
	fa[get(x)]=get(y);
}
int read()
{
	int x=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}
bool check(int x,int y)
{
	int sum=0,ti=0;
	if(get(x)!=get(y)) return false;
	bool ca=false;
	while(!ca){
		ti++;
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	t=read();
	while(t--){
		ans=0;
		memset(is,0,sizeof(is));
		memset(ca,0,sizeof(ca));
		n=read();
		d=read();
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		for(int i=1;i<=n;i++){
			x[i]=read();
			if(i==1) continue;
			if(x[i]-x[i-1]<=d){
				ca[i][0]=true;
			}
			if(x[i]-x[i-2]<=d){
				ca[i][1]=true;
			}
		}
		for(int i=1;i<=n-3;i++){
			if(!ca[i+1][0]){
				continue;
			}
			if(!ca[i+2][0]){
				continue;
			}
			if(!ca[i+3][0]){
				continue;
			}
			if(!ca[i+2][1]){
				continue;
			}
			if(!ca[i+2][1]){
				continue;
			}
			ans++;
		}
		printf("%lld\n",ans);
	}
}