#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	cout<<a[n-m+1];
	return 0;

}
