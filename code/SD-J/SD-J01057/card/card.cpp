#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
const int MAXM =35e5 + 5;
int n, m;
int a[MAXN];
int cnt[MAXM];
int num;
vector<int> s;

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cnt[i] = n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		bool flag = true;
		for(int j = 0; j < num; j++)
		{
			if(!flag)
			{
				s[j] = 0;
				num--;
			}
			if(s[j] == a[i]) 
			{
				flag = false;
				s[j] = a[i];
			}
		}
		if(flag) s.push_back(a[i]), num++;
		//cout << '\n';
	}
	for(int i = 1; i <= m; i++)
	{
		cout << cnt[i] << " ";
	}
	
	return 0;
}//Trick||Treat!
