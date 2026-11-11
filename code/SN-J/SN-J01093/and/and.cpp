#include<bits/stdc++.h>
using namespace std;
int n,m;
int  main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int maxn =0,sn =0 , x=0;
	for(int i = 1 ; i <= n ; i++){
		cin >> x;
		for(int j = 1 ; j <= m-1;j++){
			cin >> sn;
			x and sn;
		}
		maxn = max(x , maxn);
	}
	cout << maxn;

	
	return 0;
}

