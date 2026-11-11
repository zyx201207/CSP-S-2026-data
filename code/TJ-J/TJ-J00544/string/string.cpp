#include <bits/stdc++.h> 
using namespace std;
char dj;
vector <char> a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,dk = 0,cs = 0,b = -1;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		int k;
		char j;
		cin >> k >> j;
		if (k > dk) 
		{
			dk = k;
			dj = j;
		}
		for (int s = 1;s <= k;s++) a.push_back(j);
	}
	if (a.size() % 2 == 1) b = a.size()/2;
 	for (int i = 0;i < a.size();i++) if (a[i] != dj && i != b) cs++;
	cout << cs;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
