#include<bits/stdc++.h>
using namespace std;
const int MX = 5e5; 
long long n,m,a[MX + 10],lmx = -1,c,ans = 0,k = 0,l;
struct node
{
	long long cnt=0,id;
}t[MX + 10];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> l;
	for(int i = 1;i <= n;i++)
	{
		int j;
		cin >> a[i];
		for(j = 1;j <= k;j++)
		{
			if(t[j].id==a[i])
			{
				t[j].cnt++;
				break;
			}
		}
		if(j > k)
		{
			t[++k].id = a[i];
			t[k].cnt++;
		}
	}
	for(int i = 1;i <= k;i++)
	{
		ans = t[i].cnt,m = l;
		for(int j = 1;j <= k;j++)
		{
			if(t[j].id >= t[i].id)continue;
			if(m<=0)break;
			c = t[j].cnt*(t[i].id-t[j].id);
			if(c > m)
			{
				ans+=(m/(t[i].id-t[j].id));
				break;
			}
			else 
			{
				ans+=t[j].cnt;
				m-=c;
			}
		}
		lmx = max(lmx,ans);
	}
	cout << lmx << '\n';
	return 0;
}
