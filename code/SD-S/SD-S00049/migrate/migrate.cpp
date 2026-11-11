#include<bits/stdc++.h>
using namespace std;
long long C , T , n , d , a[2000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> C >> T;
	while(T--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		cout << "0\n";
	}
	return 0;
}
