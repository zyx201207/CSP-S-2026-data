#include<bits/stdc++.h>
using namespace std;
int t=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	for(int i=1; i<=n; i++){
		int a;
		cin >> a;
		t=max(t,a);
	}
	cout << t;
	return 0;
}