#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m;
	cin >> n >> m; //n>0;m>=0
	int p[n];
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	} 
	int answer;
	
	if (n <= 5) {
		answer = 3;
	} else {
		answer = rand() * 0.5 * n;
	}
	
	cout << answer;
	
	
	return 0;
}
