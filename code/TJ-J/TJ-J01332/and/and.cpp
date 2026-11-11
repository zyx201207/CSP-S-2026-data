#include<bits/stdc++.h>
using namespace std;
int m,n;
long long a[200050];
//ภÛมห 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	if(m==1){
		cout << a[n-1];
	}else{
		int sum=a[n-1];
		for(int i=n-1;i>=n-m;i--){
			sum=sum&a[i];
		}
		cout << sum;
	}
	return 0; 
}
