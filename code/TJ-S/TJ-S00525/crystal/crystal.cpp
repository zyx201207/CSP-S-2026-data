#include<bits/stdc++.h>
using namespace std;


long long n , m;
long long a[500005] , ans[500005];
long long cnt = 0;
long long jishu = 1;
long long maxn = 0;

int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	
	
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	
	for(int i = 1 ; i <= n ; i++){
		for(int j = i + 1 ; j <= n ; j++){
			cnt = 0;
			for(int k = i ; k < j ; k++){
				cnt += a[j] - a[k]; 
			}
			if(cnt == m){
				ans[jishu] = j - i + 1;
				jishu++;
			}
		}
	}
	
	for(int i = 1 ; i <= jishu ; i++){
		if(ans[i] > maxn){
			maxn = ans[i];
		}
	}
	cout << maxn;
}
