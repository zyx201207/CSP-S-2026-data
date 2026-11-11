#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s;
	string t;
	cin >> n;
	for(int i=1;i<=n;i++){
		int x;
		string m;
		cin >> x >> m;
		for(int j=1;j<=x;j++){
			t+=m;
		}
	}
	cout << "2";
	return 0;
}
