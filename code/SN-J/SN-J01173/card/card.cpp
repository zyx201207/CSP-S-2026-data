//王昭云  西安市曲江第一学校  SN-J01173
#include <iostream>

using namespace std;

int n,m,a,firstid[300005];
string s,news,tmps;
bool f[300005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a;
		s += a + '0';
	}
	for(int t = 0;t < n;t++)
	{
		for(int i = 0;i < n;i++)
		{
			if(f[s[i]])
			{
				for(int j = 0;j < firstid[s[i]];j++)
					tmps += news[j];
				f[s[i]] = 0;
				news += s[i];
				for(int j = i;j < n;j++)
					tmps += s[j];
				news = tmps;
				tmps = "";
				continue;
			}
			if(!f[s[i]])
			{
				f[s[i]] = 1;
				firstid[s[i]] = i;
				news += s[i];
			}
		}
		cout << news;
		news = "";
	}
	return 0;
}

