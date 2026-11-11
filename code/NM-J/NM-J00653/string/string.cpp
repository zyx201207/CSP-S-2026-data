#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n = 0;
	int k = 0;
	int m = 0;
	cin>>n;
	int x[n+5] = {};
	char y[n+5] = {};
	bool f = true;
	for(int i = 0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	for(int i = 0;i<n;i++){
		k = k +x[i];
	}
	if(k%2!=0){
		for(int i = 0;i<(n-1)/2-1;i++){
			if(y[i]!=y[n-1-i]){
				if(x[i]>x[n-1-i]){
					x[i] = x[i] - x[n-1-i];
					m+=x[n-1-i];
				}else{
					x[n-1-i] = x[n-1-i]-x[i];
					m+=x[i];
				}
			}
		}
		if(x[(n-1)/2+2]>x[(n-1)/2]) {
			if(x[(n-1)/2+2]>x[(n-1)/2+1]){
				m+=x[(n-1)/2+1];
			}
		}
	}else{
		if(n%2==0){
			for(int i = 0;i<n/2-1;i++){
				if(y[i]==y[n-1-i]){
					f = false;
				}else{
					if(x[i]>=x[n-1-i]){
						m+=x[n-1-i];
					}else{
						m+=x[i];
					}
				}
			}
			if(f == true){
				m = k/2;
			}
		}else{
			for(int i = 0;i<n/2-1;i++){
				if(y[i]==y[n-1-i]){
					f = false;
				}else{
					if(x[i]>=x[n-1-i]){
						m+=x[n-1-i];
					}else{
						m+=x[i];
					}
				}
			}
			if(f == true&&k%2==0){
				m = k/2;
			}else if(f == true&&k%2!=0){
				m = k/2-1;
			}
		}
		
	}
	cout<<m;
	return 0;
	
} 
