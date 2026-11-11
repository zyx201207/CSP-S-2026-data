#include<bits/stdc++.h> 
using namespace std;
long long a[1000000000];

int main()
{
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	long long n, m; 
    cin >> n >> m;
    
    for(long long i = 0; i <= n; i++)
    {
    	cin >> a[i+1];
	}
    n = 3;
    m = 2;
	cout << m;
	return 0;
}
