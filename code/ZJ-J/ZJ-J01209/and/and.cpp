#include<bits/stdc++.h>
using namespace std;
long long p2[32]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};
long long dp[200005]={};
struct Node{
	long long x;
	long long pw;
	bool visit;
}a[200005];
bool cmp(Node A,Node B)
{
	return A.x>B.x;
}
long long fd(long long X)
{
	long long l=0,r=30;
	while(l+1<r)
	{
		int m=(r-l)/2+l;
		if(X>=p2[m]) l=m;
		else r=m-1;
	}
	if(X==3||X==2) return 1;
	if(X==1) return 0;
	return r;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].x;
		a[i].pw=fd(a[i].x);
	}
	sort(a,a+n,cmp);
	dp[0]=0;
	dp[1]=a[0].x;
	a[0].visit=1;
	int lmax=a[0].pw;
	long long ans=a[0].x
	for(int i=2;i<=m;i++)
	{
		ans=ans&a[i-1].x;
	}
	cout<<ans;
	return 0;
}