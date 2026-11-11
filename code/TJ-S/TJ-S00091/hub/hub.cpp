//hub
#include <bits/stdc+++.h>;
using namespace std;

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,r,n,o;
	cin >> c >> t >> r >> n >> o;
	for (int i = 1; i <= t; i++){
		cout << (c + n + o) / (t + r) +2;
		
	}
	return 0;
}

