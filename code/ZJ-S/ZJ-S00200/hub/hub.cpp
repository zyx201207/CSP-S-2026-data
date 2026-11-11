#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	int n,k;
	cin >> n >> k;
	int a[100010][2];
	for(int i = 1;i <= n;i++){
		cin >> a[i][1];
		cin >> a[i][2];
	}
	for(int i = 1;i <= n/k;i++){
		cout << a[(i+1)/2][(i+1)%2] << endl;
	}
	return 0;
}
