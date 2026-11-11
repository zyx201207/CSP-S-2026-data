#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,c=0;
	cin >> n;
	char a[n];
	int b[n];
	for (int i=0;i<n;i++){
		cin >> b[i] >> a[i];
		c+=b[i];
		
	}
	char x[c];
	int e=1;
	for (int i=0;i<n;i++){
		for (int j=e;j<=b[i];j++){
			x[j]=a[i];
			cout <<x[j];
		}
		e+=b[i];
	}
	int u=0;
	if (c%2==0){
		
		int y=0,s=-1;
		while (s>=y){
		if (x[y]!=x[s]){
			u++;
		}
		y++;
		s--;
		
		
		
		}
	}
	cout << u;
	
	return 0;
}
