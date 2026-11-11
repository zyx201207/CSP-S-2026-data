#include<bits/stdc++.h>
using namespace std;
int c,n,m,k,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> k >> d >> q; 
	for(int i = 0;i < n;i++){
		int t = 0;
		int a[100001];
		for(int i = 0;i < m;i++){
			cin >> a[i];
			t += a[i];
		}
		int v = 0;
		for(int i = 0;i < m;i++){
			cin >> a[i];
			v += a[i];
		}
		if(n <= 3){
			if(n == 1){
				cout << t;
			}else if(n == 2){
				cout << t + v;
			}else{
				int y;
				cout << t + v + y;
			}
		} 
	}
	return 0;
}
