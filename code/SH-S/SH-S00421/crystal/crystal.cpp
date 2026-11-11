#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int m,n,g;
	cin >> m >> n;
	int a[m];
	for(int i=0; i<m; i++) {
		cin >> a[i] ;
	}
	for(int i=0; i<m; i++) {
		for(int j=0; j<m-1; j++) {
			if(a[j]>a[j+1]) {
				g=a[j+1];
				a[j+1]=a[j];
				a[j]=g;
			}
		}
	}
	int z[m-1][m];
	for(int i=0; i<m-1; i++) {
		for(int j=0; j<m; j++) {
			if(a[i+1]>a[j]) {
				z[i][j]=a[i+1]-a[j];
			} else {
				z[i][j]=0;
			}
		}
	}
	//for(int i=0; i<m-1; i++) {for(int j=0; j<m; j++) {cout<<z[i][j]<<" ";}cout<<endl;}
	int p;
	int b[m-1];
	for(int i=0; i<m-1; i++) {
		for(int j=0; j<m; j++) {
			if(z[i][j]==0){
				break;
			}
			b[i]+=z[i][j];
			//cout << i<<" "<<j<<endl<<b[i]<<" "<<z[i][j]<<endl;
			
		}if(b[i]>n){
			p=i-1;
			break;
		}
	}
	int q;
	for(int i=0; i<m; i++) {
		if(z[p][i]!=0) {
			q++;
		} else {
			break;
		}
	}
	for(int i=0;; i++) {
		if(a[q]==a[q+1]) {
			q++;
		} else {
			break;
		}
	}
	cout << q+1;
	return 0;
}
