#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int a[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	int n,d;
	while(t--){
		cin >> n >> d;
		bool b=1;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		for(int i=2;i<=n-1;i++){
			if(a[i]-a[i-1]!=a[i+1]-a[i]){
				b=0;
			} 
		}
		if(b==0) break;
		int m = a[2] - a[1];
		if(m<2*d) cout << 0 << endl;
	}
	return 0;
}
