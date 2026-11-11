#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	string s;
	int a;
	char x;
	for(int i=1;i<=n;i++){
		cin >> a >> x;
		for(int j=0;j<a;j++){
			s+=x;
		}
	}
	long long sum=0;
	for(long long i=0;i<(s.size()+1)/2;i++){
		if(s[i]!=s[s.size()-i-1]) sum++;
	}
	cout << sum; 
	return 0;
}
