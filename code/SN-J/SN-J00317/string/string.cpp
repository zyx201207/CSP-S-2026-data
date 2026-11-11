#include<bits/stdc++.h> 
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int a[n];
	string b[n];
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i];
	}
	int c;
	for(int r=0;r<n;r++){
		c += a[r];
	}
	string k[c];
	int cnt = 0;
	for(int j=0;j<n;j++){
		for(int m=0;m<a[j];m++){
			k[cnt] = b[j];
			cnt++;
		}
	}
	int count = 0;
	for(int p=0;p<(n/2);p++){
		if(k[p] != k[c-p-1]){
			count++;
		}
	}
	cout << count;
	
	
	
	return 0;
}
