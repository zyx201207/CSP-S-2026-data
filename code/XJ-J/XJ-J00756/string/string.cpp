#include <bits/stdc++.h>
using namespace std;
long long n;
int main(){
	freopen("string.in",'r',stdin);
	freopen("string.out",'w',stdout);
	cin >> n;
	string s;
	long long sum;
	long long cnt=0;
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		string b;
		cin >> b;
		for(int j=1; j<=a; j++){
			s+=b;
		}
	}
	string x = "";
	for(int i=s.size()-1; i>=0; i--){
		x += s[i];
	}
	if(x==s) cout << 0;
	else{
		if(s.size()%2==0){
			sum = s.size()/2;
			for(int i=0; i<sum; i++){
				if(x[i]!=s[i]){
					cnt++;
				}
			}
		}
		else{
			sum = s.size()/2+1;
			for(int i=0; i<sum; i++){
				if(x[i]!=s[i]){
					cnt++;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}