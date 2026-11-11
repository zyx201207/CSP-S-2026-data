#include <bits/stdc++.h>
using namespace std;

long long a[100005];
int main(){
	int c,t;cin>>c >>t;
	while(t--){
		int n,d;cin >>n >> d;
		memset(a+1,0,n);
		int cnt = 0;
		for(int i = 1; i<=n;i++){
			cin >> a[i];
		}
		for(int i = 1; i<=n; i++){
			a[i] = a[i]-a[i-1];
		}
		a[1]=0;
		for(int i = 1;i<=n;i++){
			int min = 1e9;
			int fei = 0;
			for(int j = 1;j<i;j++){
				fei+=a[i];
			}
		}
	}
	
	return 0;
}
