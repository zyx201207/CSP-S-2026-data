#include <iostream>
using namespace std;
int main() {
	int n,m;
	cin>>n>>m;
	int a[n];
	int q[m];
	int h[m];
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	for(int i=0; i<m; i++) {
		q[i]=i+1;
		h[i]=0;
	}
	for(int l=0; l<m; l++) {

		for(int i=1; i<=n; i++) {
			int b[n];
			for(int j=0; j<n; j++) {
				b[j]=a[j];
			}
			for(int j=i; j<n; j++) {
				for(int x=i; x<j; x++) {
					if(b[x]==b[j]) {
						for(int g=x; g<j; g++) {
							b[g]=-1;
						}
						break;
					}

				}
			}
			for(int o=i; o<n; o++) {
				if(b[o]==q[l]) {
					h[l]++;
				}
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<h[i];
	}
	return 0;
}