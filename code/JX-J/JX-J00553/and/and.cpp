#include<iostream>
#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n,k,cw[N][32],a,xz[N],h[32],ans[32],cnt,sum,t;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a;
		for(int j = 1;a;j++,a/=2)
		{
			if(a & 1)
			{
				cw[i][j] = 1;
				h[j]++;
			}
			//cout << cw[i][j];
		}
		//cout << endl;
	}
	for(int w = 31;w >= 1;w--)
	{
		//int pd = pow(2,w - 1);
		cnt = 0;
		if(h[w] < k) continue;
		for(int i = 1;i <= n;i++)
		{
			if(xz[i]) continue;
			if(cw[i][w]) cnt++;
			else xz[i] = w;
		}
		if(cnt >= k) ans[w] = 1;
		else
		{
			for(int i = 1;i <= n;i++) if(xz[i] == w) xz[i] = 0;
		}
	}
	t = 1;
	for(int i = 1;i <= 31;i++)
	{
		sum += t * ans[i];
		t *= 2;
	}
	cout << sum;
	return 0;
}
