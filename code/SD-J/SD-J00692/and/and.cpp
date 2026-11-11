#include <bits/stdc++.h>
using namespace std;
const int size = 2e5 + 5;
int n,m,ans;
struct tong
{
	int num,cnt;
};
tong a[size],b[size];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i].num;
		b[i].num = a[i].num;
	}
	while(m--)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				if(b[i].cnt == 0)
				{
					b[i].num &= b[j].num;
					b[i].cnt++;
				}
				else
				{
					b[i].num = max(b[i].num,b[i].num & b[j].num);
					b[i].cnt++;
				}
			}
		}
	}
	for(int i = 1;i <= n;i++)
		ans = max(ans,b[i].num);
	cout << ans;
	return 0;
}
