#include <bits/stdc++.h>
using namespace std;
char a[1000000001];
int main(){
	int n;
	cin>>n;
	int k=0,m=0;
	for(int i=0; i<n; i++) {
		int b;
		char c;
		cin>>b>>c;
		for(int j=0; j<b; j++) {
			a[k]=c;
			k++;
		}
		m=m+b;
	}
	int x=m-1;
	int s=0;
	for(int i=0; i<n; i++) {
		if(a[i]!=a[x]) {
			s=s+1;
		}
		x--;
	}
	cout<<s;
	return 0;
}
