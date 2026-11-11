#include <bits/stdc++.h>
using namespace std;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin >> n;
	long long l=0;
	for(int i=1;i<=n;i++){
		long long a;cin >> a;
		l+=a;
		cin >> c[i];
	}
	int f=1;
	for(int i=1;i<=n/2;i++){
		if(c[i]!=c[n-i+1])f=0;
	}
	if(f)cout << 0;
	else cout << l/2;
	return 0;
}