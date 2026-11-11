#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	long long n;
	long long m;
	cin >> n;
	cin >> m;
	long long a[n+5];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	long long b[n+5];
	int d = 0;
	for(int q=1;q<=m;q++){
	long long w = 0;
	for(int j=n;j>0;j--){
		//cout <<'g'<<j<<'g';
		//for(int c=0;c<n;c++){
		//	if(a[j] == b[c]){
		//		d = 1;
				
		//	}
		//}
		//if(d == 1){
		//	d = 0;
		//	continue;
		if(a[j]-1 == a[j+1]) w++;
		if(a[j] == q){
			
		cout << j+1 - w;
		w = 0;
	}
		//b[j] = j;
	}
	}

	/*
	long long e=1;
	for(int j = n;j>=0;j--){
		if(a[j-1] == e){
			cout << j;
			e++;
		}
		//cout << e;
		cout << 's' << j <<'s';
		if(e<m&&j<2){
			j = n;
			cout << 'a';
		}
	}
	*/
	return 0;
}
