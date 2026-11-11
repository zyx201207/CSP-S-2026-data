#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int m,n,sum;
	cin >> n >> m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(m==n){
		sum = a[1];
		for(int i =2;i<=n;i++){
			sum|=a[i];
		}
		cout << sum;
	}
	if(m==1){
		sort(a,a+n+1);
		cout << a[n];
	}
	return 0;
} 
