  #include <bits/stdc++.h>
  using namespace std;
  int sum[100005];
  int sum1[100005];
  int san[200005];
  int main(){
    freopen("card.in ", "r", stdin); 
  	freopen("card.out", "w", stdout);
  	int n, m;
  	cin >> n >> m;
  	for(int i =0; i < n; i++){
  		int x;
  		cin >> x;
  		sum[i] = x;
	  }
	  int dq, d = 0;
	for(int i = 1; i <= n; i++){
		dq = 0;
		d = 0;
		int v = 0;
		for(int j = i - 1; j < n; j++){
		 for(int k = dq; k >= 0; k--){
		 	if(sum1[k] == sum[j]){
		 		for(int o = k; o <= dq; o++){
		 			sum[i - 1 + v++] = sum1[o];
		 			sum1[o] = 0;
				 }
				 dq = k + 1;
				 sum1[k] = sum[j];
				 d = 1;
				 break;
			 } 
		 }
		 if(d == 0){
		 	sum1[dq++] = sum[j];
		 }
		 d = 0;
		}
		for(int l = 0; l < dq; l++){
			san[sum1[l]]++;
			sum1[l] = 0;
		}
	}
	for(int i = 0;i < m; i++){
		cout << san[i];
		if(i != m - 1){
			cout << " "; 
		}
	}
  	return 0;
  }  
