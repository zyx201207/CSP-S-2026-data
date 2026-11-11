#include<iostream>
#define ll long long
using namespace std;

const int N = 5e5 + 5;
int n,m,a[N],nex[N],nexs[N],qz[N],ans[N];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = n;i >= 1;i--)
	{
		if(nexs[a[i]]) nex[i] = nexs[a[i]];
		nexs[a[i]] = i;
	}
	for(int i = 1;i <= n;i++)
	{
		if(nex[i] != 0) qz[nex[i]] += qz[i] + 1;
		else
		{
			ans[a[i]] += qz[i] + 1;
			qz[i + 1] += qz[i] + 1;
		}
		//cout << qz[i];
	}
	for(int i = 1;i <= m;i++) cout << ans[i] << ' ';
	return 0;
}
