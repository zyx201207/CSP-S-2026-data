#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],f[N],st[N][19],lg[N];
int m,n;
void init()
{
	lg[0]=lg[1]=0;
	for(int i=2;i<=N;i++)
	{
		lg[i]=lg[i/2]+1;
	}
	//cout<<lg[N]<<endl;
}
int query(int l,int r)
{
	int len=r-l+1;
	int l_g=lg[len];
	return max(st[l][l_g],st[r-(1<<l_g)+1][l_g]);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}	
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		st[i][0]=a[i];
		f[i]=f[i-1]+a[i];	
	}
	init();
	int ans=1;
	for(int j=1;j<=lg[n];j++)
	{
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
	for(int l=1,r=1;r<=n;r++)
	{
		int len=r-l+1;
		while(query(l,r)*len-(f[r]-f[l-1])>m&&l<=r)
		{
			l++;
			len=r-l+1;
		}
		len=r-l+1;
		ans=max(ans,len);
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
