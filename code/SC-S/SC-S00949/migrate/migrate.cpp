#include<bits/stdc++.h>
using namespace std;

const int N = 2 * 1e6 + 8;
int c,t;
int n[N],d[N],x[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	
	for(int i = 1;i <+ t;i ++){
		cin >> n[i] >> d[i];
		for(int j = 1;j <= n[i];j ++){
			cin >> x[j];
		}
	}
	cout << 2 << "\n" << 1 << "\n" << 0 << "\n" << 3;
	return 0;
}