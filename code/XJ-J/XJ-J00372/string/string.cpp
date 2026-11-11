#include <bits/stdc++.h>
using namespace std;

int str(long long int b, char m[]){
	long long int s = 0;
	for(long long int i=0;i<b/2+b%2;i++){
		if(m[i] == m[b-1-i]) s ++;
	}
	if(s == b/2+b%2) return true;
	else return (b/2+b%2) - s;
} 

int main(){
	//freopen("string.in", "r", stdin);
	//freopen("string.out", "w", stdout);
	
	long long int n;
	cin >> n;
	long long int num[n];
	char word[n];
	long long int l = 0;
	for(long long int i=0;i<n;i++){
		cin >> num[i] >> word[i];
		l += num[i];
	}
	
	char word2[l];
	long long int x = 0;
	for(long long int i=0;i<n;i++){
		for(long long int j=0;j<num[i];j++){
			word2[x] = word[i];
			x ++;
		}
	}
	
	if(str(l, word2) == true){
		cout << 0;
		return 0;
	}
	
	cout << str(l, word2);
	
	return 0;
}
