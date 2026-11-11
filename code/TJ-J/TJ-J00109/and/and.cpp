#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100010];
int sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n>>m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}	
	for(int i=0;i<n;i++){
		sum = sum&&a[i]; 
	}
	cout << sum;
	
	return 0;
}
