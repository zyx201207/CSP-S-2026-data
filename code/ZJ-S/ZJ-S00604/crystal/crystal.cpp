#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m;
	cin >> n >> m;
	if(n<=5000){
		
		long long a[n] = {0};
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		
		long long sum = 0;
		for(int i=1;i<=n;i++){
			sum += a[i];
			}
		sum+=m;
		long long r = sum/n;
		long long cc;
		for(int i=1;i<=n;i++){
			if(a[i]<r){
				cc++;
			}
		}
		cout << cc;
		
		
		
		
		
	}
	
	return 0;
}