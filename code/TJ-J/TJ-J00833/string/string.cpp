#include<bits/stdc++.h>
using namespace std;

long long a[200005];
char c[200005];
//char c2[]
long long n;



int main(){
	
	freopen("string.in",  "r" , stdin);
	freopen("string.out" , "w" , stdout);
	
	
	cin >> n;
	
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i] >> c[i];
	}
	
	if(n == 1){
		cout << 0;
	}
	else if(n == 2){
		if(c[1] == c[2]){
			cout << 0;
		}
		else{
			cout << min(a[1] , a[2]);
		}
	}
	else{
		//cout << n / 2;
		
		long long sum = 0;
		
		for(int i = 1 ; i <= n ; i++){
			sum += a[i];
		}
		
//		for(int i = (n + 1) / 2 + 1 ; i <= n ; i <= sum ; i++){
//			
//		}
		
		
		cout << sum / 2;
	}
	
	
} 
