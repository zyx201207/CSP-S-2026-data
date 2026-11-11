/*
20261031
T	W	D
27	20	20
	9
W	15:43
D	15:52
*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int N=1e6+5;
ll a[N];
int f[3][N],g[3][N],L[N],R[N];
void ATRI()
{
	int n;ll m;cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=n,p=n;i;--i)
	{
		while(a[p]-a[i]>m)--p;
		R[i]=i==p?0:p;
	}
	for(int i=1,p=1;i<=n;++i)
	{
		while(a[i]-a[p]>m)++p;
		L[i]=i==p?0:p;
	}
	for(int i=1;i<=n;++i)
	{
		f[0][i]=f[1][i]=1;
		for(int j:vl[i])f[1][i]+=f[0][j];
		if(L[i]&&R[L[i]]==i)f[0][i]+=f[0][L[i]],f[1][i]+=f[1][L[i]]-f[0][L[i]];
		f[2][i]=f[1][i];
		if(R[i-1]==i)f[2][i]-=f[L[i]==i-1][i-1];
	}
	for(int i=n;i;--i)
	{
		g[0][i]=g[1][i]=1;
		for(int j:vr[i])g[1][i]+=g[0][j];
		if(R[i]&&L[R[i]]==i)g[0][i]+=g[0][R[i]],g[1][i]+=g[1][R[i]]-g[0][R[i]];
		g[2][i]=g[1][i];
		if(L[i+1]==i)g[2][i]-=g[R[i]==i+1][i+1];
	}
	ll ans=0;
	for(int i=1;i<n;++i)ans+=1ll*f[2][i+1]*g[2][i];
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;cin>>c>>t;while(t--)ATRI();
	return 0;
}