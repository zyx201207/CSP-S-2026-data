#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,y;
	cin>>c>>y;
	mt19937 a;
	a.seed(time(0));
	while(y--)
	{
		cout<<a()%6<<'\n';
	}
	return 0;
}

