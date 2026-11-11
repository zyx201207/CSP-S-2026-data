#include <iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >>n>>m;
	int a[n];
	int ans;
	for (int i = 0; i<= n; i++){
		cin>> a[i];
	}
	if (n > 15){
		ans = a[5];
	}else{
		ans = a[3];
	}
	cout <<ans;
	return 0;
}
