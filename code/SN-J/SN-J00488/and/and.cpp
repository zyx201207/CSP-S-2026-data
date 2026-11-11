#include <bits/stdc++.h>
using namespace std;

int a[200005],b[200005];

int main(){
	int n,m;
	cin>>n>>m;
	for (int i = 1;i <= n;i++) cin>>a[i];
	if (m==2){
		int k = 0;
		for (int i= 1;i <= n;i++){
			for (int j = i+1;j <= n;j++){
				b[k] = a[i]&a[j];
				k++;
			} 
		} 
		sort(b,b+k);
		cout<<b[k-1];
	}else if (m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
	}
	return 0;
}
