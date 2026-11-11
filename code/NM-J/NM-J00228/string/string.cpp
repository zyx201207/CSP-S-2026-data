#include<bits/stdc++.h>
long long isPrime(long long n){
}
long long gcd(long long a,long long b){
	if(a == b){
		return a;
	}
	if(a == 1|| b== 1){
		return 1;
	}
	if(a>b){
		a-=b;
		if(isPrime(a) == true){
			return a;
		}
	}else if(b > a){
		b -= a;
		if(isPrime(b) == true){
			return b;
		}
	}
}
using namespace std;
int main(){
  int n;
  string s=" "; b=" ";
  cin >> n;
  int gcdn = 0;
  for(int i = 0;i < n;i++){
  	long long t;
  	char a;
	  cin >> t >> a;
	   for(int j = 0;j < n;j++){
	   	s += a;
	   }
  }
  long long ans = 0;
  if(s.length()%2 == 0){
  	for(int i = s.length();i > s.length()/2-1;i++) {
  		b = s[i];
	  }
  }else{
  	for (int i = s.length();i > s.length()/2-1;i--)
  }
	cout << s <<' ' <<b<<' ';
    return 0;
}

