#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6+1;
int c,t,n,d;
int x[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=0;i<n;i++){
			cin >> x[i];
		}
		cout << (n-1)/2 << endl;
	}
}
