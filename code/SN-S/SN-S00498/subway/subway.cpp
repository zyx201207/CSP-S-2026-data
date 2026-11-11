//柳奕曦 西安市含光中学 考号SN-S00498
//liuyixi xi an shi han guang zhong xue SN-S00498 
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int c,n,m,d,q;
	cin >> c>>n>>m>>d>>q ;
	int sum = 0;
	for(int i = 1; i <= m; i++)
	{
		int x;
		cin >> x;
		sum += x;
	}
	while(q--)
	{
		cout << sum << '\n';
	}
	

	return 0;
}
//不会 
