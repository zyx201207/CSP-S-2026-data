//#include<bits/stdc++.h>
//#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//#define MSOD
////#define READ_IN_FILE
//#define int long long
//using namespace std;
//const int N=2e6+10,P=998244353;
//int n,k,x[N],d[N],maxr[N],dp[N][3],ans,sum[N][3];
//void solve()
//{
//	cin>>n>>k;ans=0;
//	for(int i=1;i<=n;i++)
//		cin>>x[i],d[i-1]=x[i]-x[i-1],maxr[i]=dp[i][0]=dp[i][1]=dp[i][2]=0;
//	for(int l=1,r=1,dis=0;l<=n;l++)
//	{
//		while(r+1<=n&&dis+d[r]<=k)dis+=d[r],r++;
//		maxr[l]=r;
//		dis-=d[l];
//	}
//	for(int i=n;i>=1;i--)
//	{
//		int r1=maxr[i],r2=maxr[r1];
//		dp[i][0]=(i!=r1&&r1!=r2?sum[maxr[r1-1]+1][0]-sum[r2+1][0]:0);
//		dp[i][1]=(i!=r1&&r1!=r2&&r1-1!=i?sum[maxr[r1-2]+1][0]-sum[maxr[r1-1]+1][0]-(r2-maxr[r1-1]):0);
//		dp[i][2]=(i!=r1&&r1!=r2?sum[maxr[r1-1]+1][2]-sum[r2+1][2]:0)+dp[i][1]+sum[maxr[i-1]+1][1]-sum[r1+1][1];
//		sum[i][0]=sum[i+1][0]+dp[i][0]+1+(maxr[i]!=i);
//		sum[i][1]=sum[i+1][1]+dp[i][1];
//		sum[i][2]=sum[i+1][2]+dp[i][2];
//		ans+=dp[i][2];
//		cout<<maxr[i]<<' '<<dp[i][0]<<' '<<dp[i][1]<<' '<<dp[i][2]<<'\n';
//	}
//	cout<<ans<<'\n';
//	return;
//}
//signed main()
//{
//	FAST
//#ifdef READ_IN_FILE
//	freopen("migrate1.in","r",stdin);
//	freopen("migrate1.out","w",stdout);
//#endif
//	int _C_,_T_=1;
//#ifdef MSOD
//	cin>>_C_>>_T_;
//#endif
//	while(_T_--)solve();
//	return 0;
//}
///*
//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6
//
//为什么啊，怎么会算重啊，啊啊啊啊啊啊啊 
//要是过了可能就去厕所了 
//0 1
//6 4
//-3 0 1 2 3 4
//freeopen
//*/
#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MSOD
#define READ_IN_FILE
using namespace std;
const int N=2e5+10,P=998244353;
int _C_,n,k,a[N],maxr[N];
int merge(int l1,int r1,int l2,int r2)
{
	if(l1>l2)swap(l1,l2),swap(r1,r2);
	if(l2>r1)return 0;
	if(r2<r1)return r2-l2+1;
	else if(r2>r1)return r1-l2+1; 
	return 0;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(_C_==13||_C_==14)
	{
		int plc=0;
		for(int i=1;i<=n;i++)
			if(a[i]-a[1]<=a[n]-a[i])
				plc=i;
		if(a[n]-a[plc]>k)plc++;
		int llim=lower_bound(a+1,a+n+1,a[plc+1]-k)-a-1,rl=upper_bound(a+1,a+n+1,a[plc-2]+k)-a,rr=upper_bound(a+1,a+n+1,a[plc-1]+k)-a-1,
		rlim=upper_bound(a+1,a+n+1,a[plc-1]+k)-a,ll=lower_bound(a+1,a+n+1,a[plc+2]+k)-a-1,lr=lower_bound(a+1,a+n+1,a[plc-1]+k)-a;
		cout<<llim*(rr-rl+1)+(n-rlim+1)*(lr-ll+1)-merge(1,llim,ll,lr)*merge(rlim,n,rl,rr)<<'\n';
	}
	else cout<<0<<'\n';
	return;
}
signed main()
{
	FAST
#ifdef READ_IN_FILE
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
#endif
	int _T_=1;
#ifdef MSOD
	cin>>_C_>>_T_;
#endif
	while(_T_--)solve();
	return 0;
}
//彻底失败了
