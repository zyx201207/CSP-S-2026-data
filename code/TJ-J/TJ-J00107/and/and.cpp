#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	int n,m;
	cin >> n >> m;
	int a[n];
	for(int i=0;i<n;i++){
		cin >>  a[i];
	}
	sort(a,a+n);
	int b[m];
	int k=0;
	for(int i=n-1;i>=n-m;i--){
		b[k]=a[i];
		k++;
	}
	
	int g=0;
	for(int i=0;i<m;i++){
		int y=b[i],u;
		while(y!=0){
			u=y%2;
			y/=2;
			g++;
		}
	}
	int gf=g*m;
	int gy[gf];
	for(int i=0;i<m;i++){
		int y=b[i],u,gm=0;
		while(y!=0){
			gm++;
			u=y%2;
			y/=2;
			gy[gf-gm]=u;
		}
	}
	for(int i=0;i<m;i--){
		if(m=1){
			for(int j=0;j<g;j++){
				cout << j;
			}
		}
		if(m=2){
			cout << 12;
		}
		cout << 15;
	}
	return 0;
}
