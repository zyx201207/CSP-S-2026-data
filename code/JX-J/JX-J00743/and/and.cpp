#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N],ans;
int awy(int x,int y)
{
	int x1=x,bj1[N],q=1;
	while(x1!=0)
	{
		bj1[q++]=x1%2;
		x1/=2;
	}
	int y1=y,bj2[N],w=1;
	while(y1!=0)
	{
		bj2[w++]=y1%2;
		y1/=2;
	}
	int bj[N]={0};
	for (int i=1;i<max(q,w);i++)
		if (bj1[i]==bj2[i] and bj1[i]==1) bj[i]=1;
	int aa=0,sum=0;
	for (int i=1;i<max(q,w);i++) sum+=(int)(pow(2,aa++))*bj[i];
	return sum;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+n+1,a+1);
	ans=a[1];
	for (int i=2;i<=m;i++)
	{
		ans=awy(ans,a[i]);
	}
	cout << ans;
	return 0;
}
