#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n;
ll m;
ll a[N];
ll pre[N];
inline bool cmp(int x,int y)
{
	return x>y;
}
int tmp=0;
int l,r,mid;
int ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	
//	for(int i=1;i<=n;i++)	cout<<a[i]<<" ";
//	cout<<endl;
	
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+a[1]-a[i];
	}
//	for(int i=1;i<=n;i++)
//		cout<<pre[i]<<" ";
//	cout<<endl;
	for(int i=1;i<=n;i++)
	{
//		cout<<"————————-debug——————————"<<endl;
		l=i,r=n;
		while(l<=r)
		{
//			cout<<"————————-debug——————————"<<endl;
			mid=(l+r)>>1;
//			printf("第%d次,l=%d,r=%d,mid=%d,要补的数=%d\n",i,l,r,mid,pre[mid]-pre[i-1] - (mid-i+1)*(a[1]-a[i]));
			if(pre[mid]-pre[i-1]/*区间补数*/ - (mid-i+1)*(a[1]-a[i]) > m)	//中间 - 补数，就是以a[i]为最大值所需要补的 
				r=mid-1;					//中间数超过m了就不可取	
			else	//mid可行 
			{
				l=mid+1;
				ans=max(ans,mid-i+1);
			}
//			printf("第%d次,max=%d\n",i,ans);
		}
//		if(pre[n]-(a[1]-a[i]) < m)	break;
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9


0 1 5 7 8

9 8 4 2 1
0 1 6 13 21 



3



5 8
-3 -1 2 2 7

7 2 2 -3 -1


4
*/
