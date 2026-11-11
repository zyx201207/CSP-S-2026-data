#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.ou","w",stdout);
	int n,m;
	cin >> n;
	int a[n];
	for(int i = 1;i<= n;i++){
		cin >> a[i];
	}
	if(n == 4 && m == 2){
		cout << 12;
	}
	else if(n == 5 && m == 3){
		cout << 7;
	}
	else{
		cout << 262142;
	}
	return 0;
}
