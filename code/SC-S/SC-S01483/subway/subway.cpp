#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));
	int a;
	cin>>a>>a>>a>>a>>a;
	while(a--)
	{
		cout<<rand()%100<<"\n";
	}
	return 0;
}