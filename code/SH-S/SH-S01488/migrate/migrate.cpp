#include <bits/stdc++.h> 
using namespace std;

void migrating(int q, int w, int d){
	
}

int main(){
	freopen("migrate.in", "r",stdin);
	freopen("migrate.out", "w", stdout);
	
	int c;
	int t;
	cin >> c >> t;
	
	for(int i = 1; i <= t; i++){
		int n;
		int d;
		cin >> n >> d;
		
		int a[n+1];
		for(int j = 1; j <= n; j ++){
			cin >> a[j];
		} 
		
		long long num = 0;
		
		for(int u = 1; u <= n-1; u++){
			for(int v = u+1; v <= n; v++){
				long long sl = 100000000;
				int len = 0;
				int t = u;
				while(a[v]-a[t] > d){
					for(int g = 1; g <= v-t-1; g++){
						if(a[t+g]-a[t] >= d){
							if(g == 1){
								t = v;
								break;
							}
							else{
								t += g;
								len ++;
								
							}
							
							
						}
					}
				}
		        len++;
				if(t == v){
					break;
				}
				if(len < sl){
					sl = len;
				}
				
				
				if(sl != 1){
					
				}
				
				
				
				
				
			}
		}
		
		
		
		
		
		
	} 
	
	return 0;
}
