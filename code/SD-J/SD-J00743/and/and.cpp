  #include <bits/stdc++.h>
  using namespace std;
 int sum[400005];
  int main(){
    freopen("and.in ", "r", stdin); 
  	freopen("and.out", "w", stdout);
  	long long n, m;
  	cin >> n >> m;
  	for(int i = 0; i < n; i++){
  		cin >> sum[i];
	  }
	  int ans = 0;
	  int maxs = 0;
	  for(int i = 0; i <= n - m; i++){
	  	ans = sum[i];
	  	for(int j = 0; j < m; j++){
	  		ans &= sum[i + j];
		  }
		  if(ans > maxs){
		  	maxs = ans;
		  }
	}
	cout << maxs;
  	return 0;
  }  
