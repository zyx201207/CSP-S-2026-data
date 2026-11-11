#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int n;
	cin>>n;
	char a[n];
	int o[n];
	int num=0;
	for(int i=0; i<n; i++) {
		cin>>o[i];
		cin>>a[i];

	}
	int u=0;
	for(int i=0; i<n; i++) {
		u+=o[i];
	}
	int x[u];
	int y=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<o[i]; j++) {
			x[y]=a[i];
			y++;
		}
	}
	if(u%2==0) {
		int h=u/2;
		for(int i=0; i<h; i++) {
			if(x[i]!=x[u-1-i]) {
				num++;
			}
		}
	}
	if(u%2==1) {
		int d=u/2+1;
		for(int i=0; i<d-1; i++) {
			if(x[i]!=x[u-1-i]) {
				num++;
			}
		}
	}
	cout<<num;
	return 0;
}