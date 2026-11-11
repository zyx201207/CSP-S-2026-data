#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=a;i<=b;i++)
#define file freopen("and.in","r",stdin);freopen("and.out","w",stdout);
int main()
{
	file
	ll n,m;
	scanf("%lld%lld",&n,&m);
	vector<ll> a(n+1);
	For(i,1,n)scanf("%lld",&a[i]);
	/*//baoli
	ll ans=0;
	For(i,1,n)
	{
		For(j,i+1,n)
		{
			printf("%lld&%lld=%lld\n",a[i],a[j],a[i]&a[j]);
			//ans=max(ans,a[i]&a[j]);
		}
	}
	//printf("%lld",ans);*/
	//DP
	if(m==1){
		ll maxn=-1;
		for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
		printf("%lld",maxn);
		return 0;
	}
	if(n<=2000&&m==2){
		ll ans=-1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		printf("%lld",ans);
		return 0;
	}
	ll **f=new ll*[n+1];
	For(i,1,n)f[i]=new ll[m+1];
	For(i,1,n)For(j,1,m)f[i][j]=0;
	f[1][1]=a[1];
	For(i,2,n)f[i][1]=max(a[i],f[i-1][1]);
	For(k,2,m){
		For(i,k,n){
			f[i][k]=max(f[i-1][k-1]&a[i],f[i-1][k]);
		}
	}
	printf("%lld",f[n][m]);
	For(i,1,n)delete[] f[i];
	return 0;
}