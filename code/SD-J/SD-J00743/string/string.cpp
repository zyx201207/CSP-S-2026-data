  #include <bits/stdc++.h>
  using namespace std;
  int main(){
    freopen("string.in", "r", stdin); 
  	freopen("string.out", "w", stdout);
  	string s, x, z;
  	long long n, m;
  	cin >> n;
  	while(n--){
  		cin >> m >> x;
  		while(m--){
  			s += x;
		  }
	  }
	  long long l = s.size();
	  long long cnt =0;
	for(int i = 0; i < l / 2; i++){
		if(s[i] != s[l - i - 1]){
			cnt ++;
		}
	}
	cout << cnt;
  	return 0;
  }  
