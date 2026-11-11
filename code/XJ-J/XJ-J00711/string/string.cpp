#include<bits/stdc++.h>
using namespace std;

int n,sum = 0,a,s;
char c;
string l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i<= n; i++){
		cin >> a >> c;
		for(int j = 1;j<= a;j++){
			l = l+c;
		}
	}
	s = l.length();
	for(int i = 0; i<=s/2; i++){
		if(l[i] != l[s-i-1]){
			sum++;
		}
	}
	cout << sum;
	return 0;
}