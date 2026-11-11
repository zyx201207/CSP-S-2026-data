#include<bits/stdc++.h>
using namespace std;
int k;
const int maxn = 2e5+10;
#define ll long long
ll s[maxn];
ll ans = 0;
char si[maxn];
ll shou,wei;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> k;
	for(int i = 1;i <= k;i++)
	{
		cin >> s[i] >> si[i];
	}
	shou = 1,wei = k;
	while(shou < wei)
	{
		if(s[shou] >= s[wei])
		{
			if(si[shou] != si[wei])
			{
				ans += s[wei];
				s[shou] -= s[wei];
				s[wei] = 0;
			}
			else
			{
				s[shou] -= s[wei];
				s[wei] = 0;
			}
			wei -= 1;
		}
		else
		{
			if(si[shou] != si[wei])
			{
				ans += s[shou];
				s[wei] -= s[shou];
				s[shou] = 0;
			}
			else 
			{
				s[wei] -= s[shou];
				s[shou] = 0;
			}
			shou += 1;
		}
	}
	cout << ans;
	return 0;
}
