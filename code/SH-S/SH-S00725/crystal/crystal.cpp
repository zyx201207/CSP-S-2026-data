#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll read()
{
	ll ret=0;
	ll pos=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-')
	{
		pos=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		ret=ret*10+(c-'0');
		c=getchar();
	}
	return ret*pos;
}
const int N=500010;
int n; 
ll m;
ll a[N];
ll s[N];
int srch(int l,int r,int gl)
{
	if(l>r) return 0;
	if(l==r) return l;
	int mid=(l+r)>>1;
	if(a[gl]*(gl-mid)-(s[gl-1]-s[mid-1])<=m) return srch(l,mid,gl);
	else return srch(mid+1,r,gl);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();//Oct31==Dec25?
	m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	s[0]=0;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int st=srch(1,i-1,i);
		ans=max(ans,i-st+1);
	}
	printf("%d",ans);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
