#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a,cnt,ans,sum,t[200001];
char c;
string s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a >> c;
		t[c-'a'+1]++;
		cnt += a;
    }
    for(int i = 1;i <= n;i++)
    {
    	if(t[i] > 0)
    	{
    		sum++;
		}
	}
	if(sum == 1)
	{
		cout << 0;
		return 0;
	}
	if(cnt % 2 == 0)
	{
		cout << cnt / 2;
	}
	else
	{
		cout << (cnt-1)/2;
	}
//		for(int j = 1;j <= a;j++)
//		{
//			s[++cnt] = c;
//		}
//	}
//	for(int i = 1;i <= cnt/2;i++)
//	{
//		if(s[i] != s[cnt--])
//		{
//			sum++;
//		}
//	}
//	cout << sum;
	return 0;
 } 
