#include<bits/stdc++.h>
#define len (R-L+1)
using namespace std;
long long k[500005];
long long a[500005];
long long n,m;
long long ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
//	for(long long i=1;i<=n;i++)	cout<<a[i]<<" ";
//	cout<<endl;
	a[0]=a[1];
	for(long long i=1;i<=n;i++)	k[i]=a[i]-a[i-1];
	long long L=1,R=1;
	long long need=0;
	while(R!=n)
	{
		while(need+(len)*k[R+1]<=m and R!=n)
		{
			R++;
			need=need+(len-1)*k[R];
		}
//		cout<<L<<" "<<R<<endl;
		ans=max(ans,R-L+1);
		
		L++;
		need=need-(a[R]-a[L-1]);
	}
	cout<<ans;
}
//6
//4 5 8 5 3 1

// 1h终于调过了
// 据调查，有三位俄罗斯人报名参加了 CCF-CSP 2026 ，他们分别是... 
// 网络状况不佳! 
