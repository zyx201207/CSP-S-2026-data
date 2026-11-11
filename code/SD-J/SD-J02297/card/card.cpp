#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,m,a[500001];
	cin>>n>>m;
	int b[m],s=0;
	for(int i=0; i<m; i++) {
		b[i]=0;
	}
	for(int i=0; i<n; i++) {
		int c;
		cin>>c;
		a[i]=c;
		if(s==0) {
			b[a[i]]++;
		} else {
			for(int j=0; j<s; j++) {
				if(a[i]==a[j]) {
					for(int k=j+1; k<s; k++) {
						a[k]=0;
					}
					s=j+1;
				} else {
					b[a[j]]++;
					s++;
				} 
			}
		}
	}
	for(int i=0; i<m; i++) {
		if(b[i]!=0) {
			cout<<b[i]<<" ";
		}
	}
	return 0;
}
