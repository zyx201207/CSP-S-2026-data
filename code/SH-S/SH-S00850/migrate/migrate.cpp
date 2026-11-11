#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,d;
		cin >> n>> d;
		for(int i=1;i<=n;i++) cin >> a[i];
		cout << n*a[d];
	}
	return 0;
}
