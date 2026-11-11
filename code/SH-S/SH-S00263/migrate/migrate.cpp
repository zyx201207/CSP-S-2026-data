#include<bits/stdc++.h>
using namespace std;
long long x[2000009],a[2000009];
int main(){
	ios::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		long long n,d,D;
		bool A = 1;
		cin>>n>>d;
		a[0] = 0;
		for(int i = 0;i < n;i++){
			cin>>x[i];
			if(i > 1){
				a[i] = x[i] - x[i - 1];
				if(D != a[i]) A = 0;
			}else if(i > 0) a[i] = x[i] - x[i - 1];D = a[i];
		}
		if(A){
			d /= D;
			if(d < 2){
				cout<<0<<endl;
				continue;
			}
			if(n >= d * 2){
				cout<<n - 2 * d + 1<<endl;
			}else{
				cout<<0<<endl;
			}
			continue;
		}
		cout<<0<<endl;
	}
	return 0;
}

