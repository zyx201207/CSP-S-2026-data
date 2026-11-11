#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,a[N],ans=-1,cnt,m;
int check(int x)
{
	int sum=1;
	if(x==1) return 2;
	for(int i=2;i<=a[n];i++)	
	{
		sum+=i;
		if(sum>x)
		{
			return i;
			break;
		}
	}	
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];	
	sort(a+1,a+1+n);
	if(a[n]>=1e5+5)
	{
		cout<<check(m);
		return 0;
	}
	for(int i=a[1];i<=a[n];i++)
	{
		priority_queue<int> pq;
		int sum=0,cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]>i)
				break;
			sum+=i-a[j];
			cnt++;
			pq.push(i-a[j]);
			while(sum>m)
			{
				sum-=pq.top();
				pq.pop();	
				cnt--;
			}		
		}	
		ans=max(cnt,ans);
	}
	cout<<ans;
} 
