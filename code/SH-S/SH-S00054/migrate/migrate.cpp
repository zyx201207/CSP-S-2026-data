#include<bits/stdc++.h>
using namespace std;
const int N = 500009;
long long x[N];
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		long long n,d;
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> x[i];
		}
		int dengcha = abs(x[2]-x[1]);
		if(dengcha >= d or 2*dengcha > d){
			cout << 0 << endl;
		}else{
			cout << n-3 << endl;
		}
	}
	return 0;
}
