#include<iostream>//T1 45tips ÇóÊ¡¶þ 
#include<algorithm>
#define int long long
using namespace std;
//Oct31==Dec25?
const int N=5e5+10;
const int limit=1e12;
int a[N],cf[N],temp[N],cnt=0,n,m,m1,j,ans,maxn=-0x3f3f3f3f3f3f3f3f;
void init(int x)
{
	m=m1;
	for(int i=1;i<=x;i++)cf[i]=temp[i];
	j=0;
}
int solve(int goal)
{
	cf[goal]=0;
	cnt=1;
	for(int i=goal-1;i>=1;i--)
	{
		cf[i]+=cf[i+1];
	}
	while(1)
	{
		j++;
		if(j>=goal)break;
		if(m>=cf[j])
		{
			m-=cf[j];
			cnt++;
		}
		else break;
	}
	init(goal);
	return cnt;
}
//int fang(int a,int b)
//{
//	for(int i=1;i<=b;i++)a*=a;
//	return a;
//}
//int f(int x,int k)
//{
//	while(1)
//	{
//		ans++;
//		if(fang(k,ans)==x)return ans;
//	}
//}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	m1=m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		cf[i]=a[i+1]-a[i];
		temp[i]=cf[i];
	}
	for(int i=1;i<=n;i++)
	{
		int res=solve(i);
		if(res>maxn)maxn=res;
	}
	cout<<maxn;
//	else
//	{
//		int k=a[2]-a[1];
//		int i=1;
//		int r=k;
//		while(1)
//		{
//			i++;
//			if(r*i/2>m)
//			{
//				i--;
//				cout<<f(r*i/2+1,k);
//				return 0;
//			}
//			r*=k;
//		}
//	}
	return 0;
}


