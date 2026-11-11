//严禹皓 西安交通大学附属中学 SN-S00503
#include<bits/stdc++.h>
using namespace std;
long long a[500005];
bool cmp(int x,int y)
{
	return x>y;
}
int main() 
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	long long m,k;
	cin >> n >> m;
	for (int i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+n+1);
	int maxn=-1e9;
	if(a[1]==a[n])cout << n;
	else 
	{
		for(int i=2;i<=n;i++)
		{
			int t =m;
			int cnt =1;
			for(int j=i-1;j>=1;j--)
			{
				t-=(a[i]-a[j]);
				if(t>=0)cnt++;
				else break;
			}
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]==a[i])cnt++;
				else break;
			}
			maxn=max(maxn,cnt);
		}
		cout << maxn;
	}
	return 0;
}
