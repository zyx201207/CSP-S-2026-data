#include<bits/stdc++.h>
using namespace std;

const int N = 2e6+2;
int n;
long long d,a[N];


void work(){
	cin >> n >> d;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		work();
	}
	return 0;
}
