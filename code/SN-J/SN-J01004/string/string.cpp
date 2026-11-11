#include<bits/stdc++.h>
using namespace std;

long long a[200005];
string s[200005];
int main(){
	int cnt = 0;
	int n;
	cin >> n;
	string c;
	for(int i = 1;i <= n;++i){
		cin >> a[i];
		cin >> c;
		for(int j = 0;j < a[i];++j){
			s[j] = c;
		}
	}
	
}
