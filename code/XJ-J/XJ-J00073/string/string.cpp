#include <bits/stdc++.h>
using namespace std;
int n;
long long a[1000000005];
string c[5];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		cin >> c[i];
	}
	for(int i = 0;i < n;i++){
		if(c[i] == c[i+1]) cout << 0;
	}
	return 0;
}


