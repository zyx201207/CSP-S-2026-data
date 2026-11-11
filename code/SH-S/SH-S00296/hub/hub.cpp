#include <bits/stdc++.h>
using namespace std;
int c,t,a,b;
int main()
{
	srand(time(0));
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	for(int i=0;i<t;i++)
	{
		cin >> a >> b;
		cout << rand()%(a+b-1)+1 << "\n";
	}
	return 0;
}
