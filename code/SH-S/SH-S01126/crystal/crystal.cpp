#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N];
int ans=1;
bool cmp(int a,int b)
{
	return a<b;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int t_1=1;
	sort(a+1,a+1+n,cmp);
	int cha=a[2]-a[1];
	for(int t1=3;t1<=n;t1++)
	{
		if(cha!=a[t1]-a[t1-1])
		{
			t_1=0;
			break;
		}
	}
	if(t_1)
	{
		for(int i=cha;i<=cha*(n-1);i+=cha)
		{
			if(m-i>=0)
			{
				m-=i;
				ans++;
			}
			else{
				break;
			}
		}
		cout << ans;
		exit(0);
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+ans;j<=n;j++)
		{
			int max_k=a[j];
			int cnt=0;
			for(int k=i;k<j;k++)
			{
				cnt+=max_k-a[k];
			}
			if(cnt<=m){
				ans=max(j-i+1,ans);
			}
		}
	}
	cout << ans;
	return 0;
}
