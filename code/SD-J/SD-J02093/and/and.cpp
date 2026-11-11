#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],sum = 0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;i++){
		cin>>a[i];
	}if (m == 1){
		for (int j = 1;j <= n;j++){
			sum = max(sum,a[j]);
		}
	}if (m == 2){
		for (int j = 1;j <= n;j++){
			for (int k = 1;k <= n;k++){
				if (k != j) sum = max(sum,a[k]&a[j]);
			}
		}
	}if (m == n){
		sum = a[1];
		for (int j = 1;j <= n;j++){
			sum = sum & a[j];
		}
	}cout<<sum;
	
	return 0;
}
