#include <bits/stdc++.h>
using namespace std;
long long n,ns,a,b=0,ans;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>ns;
	long long yu[n+5];
	for(int i=0; i<n; i++) {
		cin>>yu[i];
	}
	if(ns==2){
	for(int i=0; i<n; i++) {
		for(int j=1;j<n;j++){
			a=yu[i]&yu[j];
			if(a>=b){
				b=a;
			}
		}
	}
	}
	if(ns==3){
	for(int i=0; i<n; i++) {
		for(int j=1;j<n;j++){
			for(int w=2; w<n; w++) {
			a=yu[i]&yu[j]&yu[w];
			if(a>=b){
				b=a;
			}
			}
		}
	}
	}
	if(ns==4){
	for(int i=0; i<n; i++) {
		for(int j=1;j<n;j++){
			for(int w=2; w<n; w++) {
				for(int f=3; f<n; f++){
				
				a=yu[i]&yu[j]&yu[w]&yu[f];
					if(a>=b){
					b=a;
					}
				}
			}
		}
	}
	}
	if(ns==5){
	for(int i=0; i<n; i++) {
		for(int j=1;j<n;j++){
			for(int w=2; w<n; w++) {
				for(int f=3; f<n; f++){
					for(int v=4; v<n; v++){
					
					a=yu[i]&yu[j]&yu[w]&yu[f]&yu[v];
						if(a>=b){
						b=a;
						}
					}
				}
			}
		}
	}
	}
	cout << a;
	return 0;
}
