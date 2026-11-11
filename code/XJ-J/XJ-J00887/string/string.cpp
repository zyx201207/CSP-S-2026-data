#include<bits/stdc++.h>
using namespace std;
long long n,sum;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long int i=1 ; i<=n ; i++){
		long long a;
		char b;
		cin >> a >> b;
		for(long long int i=1 ; i<=a ; i++){
			s.push_back(b);
		}
	}
	long long l=s.size();
	for(long long int i=0 ; i<l/2 ; i++){
		if(s[i]!=s[l-i-1]){
			sum++;
		}
	}
	cout << sum;
	return 0;
}
