#include <bits/stdc++.h>
using namespace std;
int a[10000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	for(int i=1;i<m;i++){
		sum=a[i]&a[i-1];
		a[i]=a[i]&a[i-1];
	}
	cout << sum;
	return 0;
}
