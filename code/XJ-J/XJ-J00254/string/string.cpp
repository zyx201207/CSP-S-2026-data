#include<bits/stdc++.h>
using namespace std;
int n,a1[10011],sum = 0;
string c1[10011];
string num,mun;
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a1[i] >> c1[i];
		for(int j = 0; j < a1[i]; j++){
		    num += c1[i];
	    }
	}
	for(int i = num.size(); i > 0; i--){
		mun += num[i];
	}
	for(int i = num.size(); i > 0; i--){
		int j = 0;
		j++;
		if (num[j] != mun[i]){
			sum++;
		}
	}
	cout << sum - 1;
	return 0;
} 
