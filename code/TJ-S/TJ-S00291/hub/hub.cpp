#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,t1,t2;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		if(n > k) cout << 1 << '\n';
		else cout << 0 << '\n';
		for(int i = 1;i < n;i++) cin >> t1 >> t2;
	}
	return 0;
}
