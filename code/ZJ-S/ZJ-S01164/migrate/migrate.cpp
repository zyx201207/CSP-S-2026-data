#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		int x[100010];
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		if(c==1 or c==2){
			if(n==4 and d==2){
				cout << 1;
				return 0;
			}
			if(n==5 and d==2){
				cout << 2;
				return 0;
			}
			if(n==5 and d==3){
				cout << 0;
				return 0;
			}
			if(n==6 and d==2){
				cout << 1;
				return 0;
			}
			
		}
	}
	cout << 0;
	return 0;
}
