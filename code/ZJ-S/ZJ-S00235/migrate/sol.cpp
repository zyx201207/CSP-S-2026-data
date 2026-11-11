/*
20261031
T	W	D
27	20	20
	9	40
W	15:43
D	15:52
F	16:32
*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll a[N],f[N],g[N];
int L[N],R[N];
vector<int>vl[N],vr[N];
void ATRI()
{
	int n;ll m;cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i],vl[i].clear(),vr[i].clear();
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
		if(R[i])vl[R[i]].push_back(i);
		if(L[i])vr[L[i]].push_back(i);
	}
	for(int i=1;i<=n;++i)
	{
		f[i]=1;
		for(int j:vl[i])
			if(L[i]==j)f[i]+=f[j];
			else ++f[i];
	}
	for(int i=n;i;--i)
	{
		g[i]=1;
		for(int j:vr[i])
			if(R[i]==j)g[i]+=g[j];
			else ++g[i];
	}
	ll ans=0;
	for(int i=1;i<n;++i)
	{
		ll cf=0,cg=0;
		for(int j:vl[i+1])if(j!=i)
			if(L[i]==j)cf+=f[j];
			else ++cf;
		for(int j:vr[i])if(j!=i+1)
			if(R[i+1]==j)cg+=g[j];
			else ++cg;
		ans+=cf*cg;
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;cin>>c>>t;while(t--)ATRI();
	return 0;
}