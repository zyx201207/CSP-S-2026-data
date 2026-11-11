#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
long long  int sum;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	int a;
	char c;
	while(n--) {
		long long a;
		char c;
		cin>>a>>c;
		for(int j=0; j<a; j++) {
			s+=c;
		}
	}
	for(int i=0; i<s.size()/2; i++) {
		if(s[i]!=s[s.size()-1-i]) {
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
