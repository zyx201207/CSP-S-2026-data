#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int c,t;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		int x[N];
		int cha;
		for(int i = 1;i <= n;i++){
			cin >> x[i];
		}
		cha = x[2] - x[1];
		int ans = 0;
		if(cha >= d){
			cout << 0 << endl;
		}
		else {
			cout << (x[n]-x[n-2]) / cha << endl;
		}
	}
	
	return 0;
} 
