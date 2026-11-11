#include<bits/stdc++.h>
using namespace std;

long long n,sum,a[100005];
char c[100005];
string k,s;
long long b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		for(int j = 1;j <= a[i];j++){
			k += c[i];
		}
	}
	for(int i = n;i >= 1;i--){
		for(int j = 1;j <= a[i];j++){
			s += c[i];
		}
	}
	for(int i = 1;i <= n;i++){
		b+=a[i];
	}
	b--;
	for(int i = 0;i <= n;i++){
		if(k == s){
			cout << i;
			break;
		}
		s[i] = k[i];
		k[b-i] = s[b-i];
	}
	return 0;
}
