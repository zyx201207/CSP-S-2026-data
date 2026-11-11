#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		if(n == k)cout << 0;
		else if(k >= n-4)cout << 1;
		else if(k == 1)cout << (n/2+2)/2;
		else if(k <= n/2+3) cout << (n/2+3-k)/4+1;
		else cout << 1;
		cout << "\n";
	}
}
