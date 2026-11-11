#include <bits/stdc++.h> 
using namespace std;

int main(){
	freopen("crystal.in", "r",stdin);
	freopen("crystal.out", "w", stdout);
	
	
	long long n;
	
	long long m;
	cin >> n >> m;
	

	
	long long a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	} 
	
	for(int i = 0 ; i < n; i++){
		int smallest = i;
		for(int j = i+1; j < n; j++){
			if(a[j] < a[smallest]){
				smallest = j;
			}		
			
		}
		int temp = a[i];
		a[i] = a[smallest];
		a[smallest] = temp;
		
	}
	
	
	long long maxx = 0;
	
	for(long long i = 1; i <= n; i++){
		long long s = 0;
		for(long long j = 0; j < i-1 ; j++){
			s += a[i-1] - a[j]; 
		}
		if(m >= s ){
			maxx = i;
		}
	}
	
	cout << maxx << endl;
	
	return 0;
}
