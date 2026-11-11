#include<bits/stdc++.h>
using namespace std;
freopen("string.in",r,stdin);
freopen("string.out",w,stdout);
int main(){
	int n;
	long long j = 0,cmp = 0;
	cin >> n;
	string S;
	for(int i = 0;i<n;i++){
		long long a;
		char c;
		cin >> a >> c;
		for(int q = 0;q<a;q++){
			S[j] = c;
			j++;
		}
	}
	for(long long i = 0;i<j/2;i++){
        cmp += !(S[i]==S[j-i-1]);
	}
	cout << cmp;
	return 0;
}
