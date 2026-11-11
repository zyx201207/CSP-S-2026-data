#include"bits/stdc++.h"
using namespace std;

int n;
vector < pair < long long , char > > ve;

int main (){
	
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	
	cin >> n;
	
	long long len = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		long long num;
		char a;
		
		cin >> num >> a;
		
		len += num;
		ve.push_back({num , a});
	}
	
	long long sum = 0;
	for(int i = 0 ; i < n / 2  ; i++)
	{
		if(ve[i].second != ve[n - i - 1].second) sum += max(ve[i].first , ve[n - i - 1].first);
	}
	
	cout << sum << endl;
	
	return 0;
}
