#include<bits/stdc++.h>
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define cfs cout<<fixed<<setprecision
#define ull unsigned long long
//#define i128 __int128
#define ll long long
#define endl '\n'
using namespace std;
int n,m;
int a[500010];
int ans[300010];
//int b[500010];
int v[300010];
int h[500010];
int f[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	IO;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		h[i]=i;
		cin >> a[i];
	}
//	int k=0;
//	for(int i=1;i<=n;i++)
//	{
//		if(a[i]!=a[i-1])
//		{
//			b[++k]=a[i];
//		}
//		ans[a[i]]++;
//	}
	for(int i=n;i>=1;i--)
	{
		if(v[a[i]]==0)
		{
			v[a[i]]=i;
		}
	}
	int x=0;
	for(int i=1;i<=n;i++)
	{
		x+=f[i];
		h[i]-=x;
		if(v[a[i]]!=i)
		{
			f[i+1]+=h[i];
			f[v[a[i]]]-=h[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans[a[i]]=max(ans[a[i]],h[i]);
	}
	for(int i=1;i<=m;i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
//千万别挂分啊，C应该卡的过吧 
