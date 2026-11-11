#include <iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	freopen ("crystal","r",stdin);
	freopen ("crystal","w",stdout);
	int m,n;
	cin >>m >>n;
	int a[n];
	for (int i =0; i<= n; i++){
		cin >>a[i];
	}
//	sort(a.begin(),a.end());
	int r = n / 2;
	int ans = 1;
	int i = 1;
	cout << m << n;
	while (m=0){
		int w = a[r] - a[r-i];
		m = m-w;
		ans ++;
		i ++;
	}
	cout << ans <<endl;
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
