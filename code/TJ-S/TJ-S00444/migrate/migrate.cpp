#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//1 2 3 4 5
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		long long t;
		bool flag = true;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
			if(i == 2){
				t = a[2] - a[1];
			}else if(i != 1){
				if(t != a[i] - a[i-1]){
					flag = false;
				}
			}
		}
		if(flag){
			cout << n - (d/t + 1) << '\n'; 
		}else{
			cout << 0 << '\n';
		}
	}
	return 0;
}
