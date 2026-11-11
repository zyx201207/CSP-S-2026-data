#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int a[n];
	char b[n];
	int c=0;
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i];
	}
	for(int i=0;i<n-1;i++){
		if(b[i]!=b[i+1]){
			c++;
		}
	} 
	cout << c;
	return 0;
}
