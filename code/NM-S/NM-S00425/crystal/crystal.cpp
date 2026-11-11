#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 10;
int n, m;
int a[N];
int b[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	long long cnt = 0;
	
	for(int i = 1;i <= n; i++){
		long long cnt2 = 1;
		long long t = m;
		for(int j = 1;j < i; j++){
			if(a[i] - a[j] <= t){
				a[j] += a[i] - a[j];
				t -= a[i] - a[j];
			}else{
				a[j] += t;
				break;
			}
		}  
		
		for(int j = 1;j <= n; j++){
			if(a[j + 1] == a[j]){
				cnt2++;
			}
			  
		}       
		      //cout << cnt2 << '\n';                               
		for(int j = 1;j <= n; j++){
			//cout << a[j] << " ";
			a[j] = b[j];
		}     
		
		      
		//ccout << '\n';   
		
		cnt = max(cnt, cnt2);     
		
	}                                                                                                                                                            		
	
	
	cout << cnt;

	return 0;
}
 
