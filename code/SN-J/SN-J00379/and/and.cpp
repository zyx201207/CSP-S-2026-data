#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int zuidade=-1;
	for(int i=1;i<=n;i++)
	{
		int qwe;
		cin>>qwe;
		if(qwe>=zuidade)
		zuidade=qwe;
	}
	cout<<zuidade;
	return 0;
}
