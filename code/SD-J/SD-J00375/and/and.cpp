#include <iostream>
using namespace std;
int main()
{
	int n,m,max = -1;
	cin >> n >> m;
	int a[n + 1];
	for (int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	for (int q = 1;q <= m; q++){
		for (int i = q;i <= n;i++){
			for (int j = i + 1;j <= n;j ++){
				if ((a[i] & a[j]) > max){
					max = a[i] & a[j];
			}
		}
	}
	}
	cout << max;

	return 0;
}
