#include <bits/stdc++.h>
using namespace std;
long long n,m;
struct XX{
	long long y;
	int xz[10000];
}a[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		int x = 1;
		cin >> a[i].y;
		cout << a[i].y<<endl;
		long long y1 = a[i].y;
		while(y1){
			a[i].xz[x] = y1%2;
			y1/=2;
			x++;
		}
		for(int j = 1;j<=x;j++){
			cout << a[i].xz[j];
		}
		cout << endl;
	}
	return 0;
}
