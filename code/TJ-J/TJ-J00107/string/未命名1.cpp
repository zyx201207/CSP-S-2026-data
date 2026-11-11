#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	int n;
	cin >> n;
	char b[n];
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i];
	}
	int s=0;
	for(int i=0;i<n;i++){
		s+=a[i];
	}
	char c[s],d[s];
	for(int i=0;i<n;i++){
		char p[a[i]]="";
		int pc=0,mn=0;
		for(int j=0;j<=a[i];j++){
			p[j]=b[i];
		}
		for(int j=pc;j<=pc+a[i];j++){
			c[j]=p[mn];
			mn++;
		}
	}
	
	
	int ghj=0;
	for(int i=n-1;i>=0;i--){
		d[ghj]=c[i];
		ghj++;
	}
	int cnt=0;
	for(int i=0;i<s;i++){
		if(c[i]!=d[i]){
			cnt++;
			c[i]=d[i];
		}
	}
	cout << cnt;
	return 0;
}
