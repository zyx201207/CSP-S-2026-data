#include <bits/stdc++.h>
using namespace std;

long long int n,a,cnt = -1,sum = 0;
char m;
char p[1000000000];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 0;i<n;++i){
		cin >> a;
		cin >> m;
		for(int i = 1;i<=a;++i){
			p[++cnt] = m;
		}
	}
	for(int i = 0;i<=cnt/2;++i){
		if(p[i]!=p[cnt-i]){
			++sum;
		}
	}
	cout << sum;
	return 0;
}
