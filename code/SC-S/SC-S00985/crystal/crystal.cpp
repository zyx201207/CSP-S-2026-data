#include<bits/stdc++.h>

#define int long long

using namespace std;

array<int , 500100> val; 

signed main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n = 0 , m = 0 , ans = 1;
	
	cin >> n >> m;
	
	for(int i = 1;i <= n;++ i) cin >> val[i];
	
	sort(val.data() + 1 , val.data() + n + 1 , [&](int x , int y){return x < y;});
	
	int l = 1 , r = 1 , sum = 0;
	
	for(int i = 2;i <= n;++ i)
	{
		++ r;
		sum += (r - l) * (val[i] - val[i - 1]);
		while(l <= r && sum > m)
		{
			sum -= (val[i] - val[l]);
			++ l;
		} 
		
		ans = max(ans , r - l + 1);
	}
	
	cout << ans << endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
 } 