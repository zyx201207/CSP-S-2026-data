#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n , m,ans=0,aa=0;
	cin >> n >> m;
	a[0]=0;
	for(int i=0;i<=n;i++){
		cin>>a[i];
		if(n==m){
			ans=a[i]&a[i-1];
			
		}
			
		
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
