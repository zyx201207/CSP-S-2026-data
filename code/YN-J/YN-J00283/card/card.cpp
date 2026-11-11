#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int N = 5e5 + 5;
const int M = 3e5 + 5;
int n, m;
int x;
unordered_map<int, int>vis;
int a[N];
int ta[N];
int ans[M];
int ed = 0;

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ta[i] = a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for(int j = 1;j<=n;j++){
			a[i] = ta[i];
		}
		ed = 0;
		for (int j = i; j <= n; j++)/*a[j]为要打的牌*/
		{
			bool flag = false;
			for (int k = j; k <= ed; k++)/*k搜索有没有之前有的编号*/
			{
				if (a[k] == a[j])
				{
					flag = true;
					ed = k; /*++ed*/
					break;
				}
			}
			a[++ed] = a[j];
		}
		for(int j  =1;j<=ed;j++){
			ans[j]++;
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
