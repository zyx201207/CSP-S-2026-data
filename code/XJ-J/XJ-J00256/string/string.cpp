#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string,out","w",stdout);
	int n;
	int a,t;
	int s[100001] = {};
	cin >> n;
	for(int i = 0;i <= n;i++)
	{
		cin >> a,t;
		for(int i = 0;i <= a;i++)
		{
			cout << t;
			s[i] = 1;
		}
			
	}
	
	
    cout << s;
	return 0;
}