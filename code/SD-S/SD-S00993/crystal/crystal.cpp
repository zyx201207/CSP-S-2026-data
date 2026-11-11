#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
const int N=5e5+5;
int n,ans;
long long m,a[N],cha[N],s[N],low[N][20];
long long query(int l,int r)
{
	int len=log2(r-l+1);
	return max(low[l][len],low[r-(1<<len)+1][len]);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){s[i]=s[i-1]+a[i];low[i][0]=a[i];}
	for(int j=1;j<=log2(n);j++)
		for(int i=1;i+(1<<j-1)<=n;i++)
			low[i][j]=max(low[i][j-1],low[i+(1<<j-1)][j-1]);
	int l=1,r=1;
	while(l<=r&&r<=n)
	{
		while(query(l,r)*(r-l+1)-s[r]+s[l-1]<=m&&r<=n){r++;}
		ans=max(ans,r-l);
		l++;
	}
	cout<<ans;
	return 0;
}

