#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	int n,d;
	while(t--){
		int sum=0;
		cin >> n >> d;
		for(int i=1; i<=n; i++){
			cin >> a[i];
		}
		for(int i=1; i<=n; i++){
			for(int j=i; j<=n; j++){
				if(i!=j && abs(a[i]-a[j])==d+1){
					sum++;
				}
			}
		}
		cout << sum << '\n';
	}
	return 0;
} 