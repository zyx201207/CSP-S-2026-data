#include<bits/stdc++.h>
#include<chrono>
#define ms microseconds
#define int long long 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define N 500005
using namespace std;
using namespace chrono; 
auto Star=system_clock::now();
auto GetTime(){return (double)(duration_cast<ms>(system_clock::now()-Star).count())*ms::period::num/ms::period::den;}
void PrintTime(){cout<<"Cost="<<GetTime()<<endl;}
int read()
{
	int t=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)) t=t*10+ch-48,ch=getchar();
	return t*f;
}
int a[N],pre[N];
int n,m;
int erfen(int r)
{
	int left=1,right=r;
	while(left<right)//最小的左端点使得《=m 
	{
		int mid=(left+right)>>1;
		if((r-mid+1)*a[r]-(pre[r]-pre[mid-1])<=m) right=mid;
		else left=mid+1;
	}
	return right;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	int i,ans=0;
	for(i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+a[i];
		int pos=erfen(i);
		ans=max(ans,i-pos+1);
	}
	printf("%lld",ans);
	return 0;
	fclose(stdin);
	fclose(stdout);
	
}

