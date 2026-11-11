#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	string a,s;
	cin >> n >> m;
	cin >> a;
	for (int i=0;i<a.size();i++)
	{
		if (a[i] != ' ') s += a[i];
	}
	sort(s.begin() , s.end());
	reverse(s.begin() , s.end());
	cout << (s[0] and s[1]);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}