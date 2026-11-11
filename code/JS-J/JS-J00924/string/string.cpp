#include<bits/stdc++.h>
using namespace std;

long long n,a,sum,ans;
string s,c;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a >> c;
		sum += a;
		while(a--)
		{
			s += c;
		}
	}
	int j = sum - 1;
	for(int i = 0;i <= sum / 2 - 1;i++)
	{
		if(s[i] != s[j])
		{
			ans++;
		}
		j--;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
