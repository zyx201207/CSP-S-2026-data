#include <bits/stdc++.h>
using namespace std;

	long long int n,a,maxa;
	string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		cin >> b[maxa+1];
		for(int j = maxa+2;j<=maxa+a;j++){
			b[j] = b[maxa+1];
		}
		maxa = maxa+a;
	}
	long long int r = n,l = 1;
	while(r>=l){
		if(b[r]==b[l]){
			if(a[r]>a[l]){
				a[r] = a[r]-a[l];
			}else{
				a[l] = a[l]-a[r]
				}
		}else{ 
			if(a[r]>a[l]){
				maxa = a[l]+maxa;
			}else{
				maxa = a[r]+maxa;
				}	
			}
			if(a[r]==0){
			r--;
			}
			if(a[l]==0){
			l++;
			}
	}
	cout << n;
	return 0;
	}
