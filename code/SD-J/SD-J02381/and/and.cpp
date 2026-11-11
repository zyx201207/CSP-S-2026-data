#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n, m, ans=0;
	scanf("%lld %lld", &n, &m);
	long long a[n + 5];
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}
	
	
	if(n <= 2000){
		if(m == 1){
			sort(a, a + n, cmp);
			printf("%lld", a[0]);
		}//6
		
		
		else if(m == n){
			ans = a[0];
			for(int i = 1; i < n; i++){
				ans = ans & a[i];
			}
			printf("%lld", ans);
		}//7
		
		
		else if(m == 2){
			for(int i = 0; i < n - 1; i++){
				for(int j = i + 1; j < n; j++){
					if(ans < ( a[i] & a[j] ) ){
						ans = a[i] & a[j];
					}
				}
			}
			printf("%lld",ans);
		}//8,9,10
	    else{
	    	sort(a, a + n, cmp);
        	ans = a[0];
        	for(int i = 1; i < m; i++){
	        	ans = ans & a[i];
        	}
        	printf("%lld", ans);
    	}
	}
	
	
	else{
		sort(a, a + n, cmp);
    	ans = a[0];
    	for(int i = 1; i < m; i++){
	    	ans = ans & a[i];
    	}    	
    	printf("%lld", ans);
	}
	
	return 0;
} 
