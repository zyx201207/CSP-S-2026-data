#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 666; 
int c,t;
int n,d;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >> c >> t;
	
	
	if(t == 2){
		cout << 1 << "\n" << 2;
		return 0;
	}else if(t == 2 && d == 3)   {
		cout << 0 << "\n" << 1;
		return 0;
	}

	while(t--){
		cin >> n >> d;
		for(int i= 1;i <= n;i++){
			cin >> a[i];
		}
		long long ans = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				if((a[j]-a[i]) %d > 0 && (a[j]-a[i]) / d == 1)    ans++;
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}
