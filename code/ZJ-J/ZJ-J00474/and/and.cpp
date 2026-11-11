#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin >> n;
	int ma=0;
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		ma=max(ma,x);
	}
	cout << ma;
	return 0;
}
