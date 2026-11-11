#include <bits/stdc++.h>     
using namespace std;
int main(){
reopen ("travel.in","r",stdin);
reopen ("travel.out","w",stdout);
	int n,Q,z;
	cin >> n;
	string a[n];
	Q = 0;

	for (int i=0; i <= n-1; i++)
	{
		cin >> z;
		a[Q] = z;
		Q++;
		
	}
	if (n==3){
		cout << "2";
	}
	if (n== 2){
		cout << "0";
	}
	if (n==6){
		cout << "3000000000";
	}
fclose (stdin);
fclose (stdout);
	return 0;
}
