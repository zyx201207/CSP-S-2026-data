#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int w[2000005],a[500005];
ll b[500005];
bool wq(int L1,int R1,int L2,int R2)
{
	return L2>=L1&&R2<=R1;
}
bool xj(int L1,int R1,int L2,int R2)
{
	return 	(L1<L2&&L1<R2&&L2>=R1)||(L2<L1&&L1<R2&&L1>=R2);
}
void push_up(int u)
{
	w[u]=w[u*2]+w[u*2+1];
}
void build(int u,int L,int R)
{
	if(L==R)
	{
		w[u]=a[L];
		return;
	}
	int M=(L+R)/2;
	build(u*2,L,M);
	build(u*2+1,M+1,R);
	push_up(u);
}
int cha2(int u,int l,int r,int L,int R)
{
	if(wq(l,r,L,R))
		return w[u];
	else if(xj(l,r,L,R))
	{
		printf("%d %d %d %d\n",l,r,L,R);
		int M=(L+R)/2;
		return cha2(u*2,l,r,L,M)+cha2(u*2+1,l,r,M+1,R);
	}
	else
		return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,sum=0,ma=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	build(1,1,n);
	int l=1,r=0;
	int ans=-2e9;
	while(true)
	{
		r++;
		if(sum+(a[r]-ma)*(r-l)<=m)
			sum+=(a[r]-ma)*(r-l),ma=a[r],ans=max(ans,(r-l+1));
		else
		{
			r--;
			break;
		}
		
	}
	while(r<=n)
	{
		r++;
		sum+=(a[r]-ma)*(r-l);
		if(sum<=m)
			continue;
		int now=0;
		for(int i=1<<30;i;i>>=1)
			if(l+now+i<r&&sum-(a[r]*(now+i+1)-(b[l+now+i]-b[l])<=m))
				now+=i;
		l+=now;
		ans=max(ans,r-l+1);
		ma=a[r];
	}
	printf("%lld",ans);
	return 0;
}

