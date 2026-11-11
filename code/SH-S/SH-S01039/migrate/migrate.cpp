#include <iostream>
#include <algorithm>
using namespace std;
int x[10005];
int n,d;
int best(int a){
	if(a < 0){
		return a - a - a;
	}else{
		return a;
	}
}
int way(int start,int end){
	for(int i=1;i<=n;i++){
		for(int j=end;j>i;j++){
			if(best(x[j] - x[i]) < d){
				return 1;
			}
		}
	}
	return 0;
}
void solve(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> n >> d;
	for(int i=1;i<=n;i++){
		cin >> x[i];
	}
	int sum = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i == j){
				continue;
			}
			sum += way(i,j);
		}
	}
	cout << sum << endl;
}
int main(){
	int c,t;
	cin >> c >> t;
	while(t--){
		solve();
	}
}
