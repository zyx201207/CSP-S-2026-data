#include <bits/stdc++.h>
using namespace std;
int n, m, ans = 1;
int s[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>s[i];
	}
	sort(s + 1, s + n + 1, greater<int>());
	cout<<s[m];
	return 0;
}
