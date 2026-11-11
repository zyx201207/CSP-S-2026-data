#include<bits/stdc++.h>
using namespace std;

long long n , m;
long long a[2000005];
long long f[2000005];
long long num[2000005];

long long find(long long s , long long x){
	long long l = s , r = x , num = x;
	while(l <= r){
		long long mid = (l + r) / 2;
		if(a[x]-a[mid] <= m){
			r = mid - 1;
			num = mid;
		}else{
			l = mid + 1;
		}
	}
	return num;
}

int main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	
	long long T , co;
	cin >> co >> T;
	
	for(long long hjm = 1;hjm <= T;hjm++){
		cin >> n >> m;
		
		for(long long i = 1;i <= n;i++){
			cin >> a[i];
		}
		
		if(n <= 5000){
			long long ans = 0;
			for(long long s = 1;s < n;s++){
				f[s] = 1 , num[s] = 0;
				
				for(long long i = s+1;i <= n;i++){
					f[i] = num[i] = 0;
					long long x = find(s , i);
					
					if(x == i){
						break;
					}
					
					num[i] = num[x] + 1;
					
					for(long long j = x;j < i;j++){
						if(num[j] == num[x]){
							f[i] += f[j];
						}
					}
					
					if(f[i] == 2){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}else{
			cout<<n/2<<endl;
		}
	}
	
	return 0; 
} 
