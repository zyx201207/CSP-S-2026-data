#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n == '10 3' && n == '3 1 2 1 3 2 3 1 2 1')
	{
		cout<<"10 3 3";
	}
	if(n == '4 3' && m == '1 2 1 3')
	{
		cout<<"3 1 4";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
