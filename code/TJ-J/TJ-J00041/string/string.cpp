#include <bits/stdc++.h>
using namespace std;
char x[200000005],c;
long long n,a,z=0,ans=0;
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a >> c ;
		for(int j=1;j<=a;j++){
			z++; 
			x[z]=c;
		}
	}
	for(int i=1;i<=z/2;i++){
			if(x[i]!=x[z-i+1]) ans++;
	}
	cout << ans;
	return 0;
}

