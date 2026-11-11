#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n = 0,m = 0,a[50010],v = 0,g = 0,u = 0;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1;i <= n;i++){
		cin >> a[i];
		long long l = 0;
		for(long long j = 1;j < n;j++){ 
		if(a[j] >= a[j+1]){
			l = a[j];
			a[j] = a[j+1];
			a[j+1] = l;
		}else{
			continue;
			}
		} 
	}
	for(long long i = 1;i <= n;i++){
		for(long long j = m;j >= 0;j--){
		g = a[i]; 
		for(long long z = n;z > 0;z--){
		a[i] += j;
		if(a[i] == a[z]){
			if(a[i] == a[z-1]){
				break;
				}else{
				continue;
				}
		}else if(a[i] < a[z]){
			if(a[i] == a[z-1]){
			break;
			}
			}else {
				for(long long b = 2;b < z;b++){
					if(a[i] == a[z-b] && z - b > 0){
						break;
					}else{
						continue;
					}
				}
			}
		}
		a[i] = g; 
		}
	}
	for(long long i = 1;i <= n;i++){
		for(long long j = m;j >= 0;j--){
			for(long long d = 2;d <= n;d++){
				for(long long y = m - j;y > 0;y--){
					u = a[d];
					for(long long z = n; z > 0;z--){
						a[d] += y;
						if(a[d] == a[z]){
						if(a[d] == a[z-1]){
							break;
							}else{
							continue;
							}
						}else if(a[d] < a[z]){
						if(a[d] == a[z-1]){
							break;
							}
							}else{
						for(long long f = 2;f < z;f++){
							if(a[d] == a[z-f] && z - f > 0){
								break;
								}else{
								continue;
								}
							}
						}
					}
				}
				a[d] = u;
			}
		}
	}
	for(long long c = 1;c < n;c++){
		if(a[c] == a[c+1] || a[n] == a[1]){
			v++;
		}else{
			continue;
		}
	}
	cout << v << endl;
	return 0;
}

