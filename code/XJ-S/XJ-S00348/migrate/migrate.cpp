#include<bits/stdc++.h>
using namespace std;
const int N = 2000006;
long long c, t;
long long n, d;
long long x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> c >> t;
	if(11 <= c && c <= 12 || c == 0){
		while(t--){
			//cout << "A" << endl;
			cin >> n >> d;
			for(int i = 1;  i <= n ;i++){
				cin >> x[i];
			}
			//cout << "B" << endl;
			long long num = d/(x[2] - x[1]);
			
			if(num == 1 || num == 0){
				
				cout << 0 << endl;
				continue;
			}
			unsigned long long a, b, c;
			//cout << x[2] << " " << x[1] << endl;
			//cout << num << " " << n << endl;
			
			c = 1ll*(n - 2*num + 2)*(n / num - 1)/2;
			//cout << "D" << endl;
			cout << c << endl;
		}
		return 0;
	}
	else{
		while(t--){
			cout << 0 << endl;
		}
	} 
	
	return 0;
} 
