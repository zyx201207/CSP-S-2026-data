#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1) cout<<0;
	else cout<<n/2;
	return 0;
}
